#include "GamePCH.h"

#include "Game.h"
#include "../../Framework/Libraries/imgui/imgui.h"
#include "Objects/Player.h"
#include "Objects/Shapes.h"
#include "Events/GameEvents.h"
#include "Objects/PlayerController.h"
#include "Objects/Enemy.h"

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062


Game::Game(fw::FWCore* pFramework) : fw::GameCore(pFramework)
{
	wglSwapInterval(m_VSyncEnabled ? 1 : 0);

	Vector2 a(1.111f, 1.111f);

	a *= 100;

	if ( a == Vector2( 111.1f, 111.1f ))
	{
		int bp = 1;
	}
	else
	{
		int bp = 1;
	}
}

Game::~Game()
{
	delete m_pShader;
	delete m_pMeshHuman;
	delete m_pMeshAnimal;
	delete m_Circle;
	delete m_pPlayerController;
	delete m_pImGuiManager;
	delete m_pEventManager;

	for (Player* player : m_Players)
	{
		delete player;
	}

	for (Enemy* enemy : m_ActiveEnemies)
	{
		delete enemy;
	}

	for (fw::GameObject* go : m_Objects)
	{
		delete go;
	}
}

void Game::Init()
{
	// OpenGL Settings
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_pImGuiManager = new fw::ImGuiManager(m_pFramework);
	m_pImGuiManager->Init();
	m_pEventManager = new fw::EventManager();
	m_pShader = new fw::ShaderProgram("Data/Basic.vert", "Data/Basic.frag");

	m_pMeshHuman = new fw::Mesh();
	m_pMeshHuman->CreateShape(meshPrimType_Human, meshNumVerts_Human, meshAttribs_Human);

	m_pMeshAnimal = new fw::Mesh();
	m_pMeshAnimal->CreateShape(meshPrimType_Enemy, meshNumVerts_Enemy, meshAttribs_Enemy);

	//Circle
	m_Radius = 4.5f;
	numberOfSides = 50;
	m_Circle = new fw::Mesh();
	m_Objects.push_back(new fw::GameObject("Circle", Vector2(5, 5), m_Circle, m_pShader, Vector4::Red(), this));
	
	m_pPlayerController = new PlayerController();

	//Player
	player = new Player("Player", Vector2(5, 5), m_pPlayerController, m_pMeshHuman, m_pShader, Vector4::Green(), this);
	m_Players.push_back(player);

	m_Circle->CreateCircle(GL_LINE_LOOP, m_Radius, (unsigned int)numberOfSides);

	currentLevel = Level1;
	gameState = Running;
	m_LevelTimer = 0.0f;
	m_WinTimer = 0.0f;
}

void Game::OnEvent(fw::Event* pEvent)
{
	m_pPlayerController->OnEvent(pEvent);

	// Process the event.
	if ( pEvent->GetType() == RemoveFromGameEvent::GetStaticEventType() )
	{
		RemoveFromGameEvent* pRemoveFromGameEvent = static_cast<RemoveFromGameEvent*>(pEvent);
		fw::GameObject* pObject = pRemoveFromGameEvent->GetGameObject();

		auto it = std::find(m_Objects.begin(), m_Objects.end(), pObject);
		m_Objects.erase(it);

		delete pObject;
	}

	if (pEvent->GetType() == SpawnEnemiesEvent::GetStaticEventType())
	{
		float angle = (rand() % 360) / 1.0f;
		angle *= (float)(PI / 180.0f);

		float x = m_Radius * cosf(angle) + 5.0f;
		float y = m_Radius * sinf(angle) + 5.0f;

		if (currentLevel == Level1)
		{
			Enemy* enemy = new Enemy("Enemy", Vector2(x, y), m_pMeshHuman, m_pShader, Vector4::Blue(), this, player);
			m_ActiveEnemies.push_back(enemy);
		}
		else if (currentLevel == Level2)
		{
			Enemy* enemy = new Enemy("Enemy", Vector2(x, y), m_pMeshHuman, m_pShader, Vector4::White(), this, player);
			m_ActiveEnemies.push_back(enemy);
		}

		
	}

	if (pEvent->GetType() == DeleteEnemiesEvent::GetStaticEventType())
	{
		DeleteEnemiesEvent* pSpawnEnemiesEvent = static_cast<DeleteEnemiesEvent*>(pEvent);
		Enemy* pEnemy = pSpawnEnemiesEvent->GetEnemy();

		auto it = std::find(m_ActiveEnemies.begin(), m_ActiveEnemies.end(), pEnemy);
		m_ActiveEnemies.erase(it);

		delete pEnemy;
	}

	if (pEvent->GetType() == CollisionEvent::GetStaticEventType())
	{
		health--;
		return;
	}

	if (pEvent->GetType() == PlayerDeathEvent::GetStaticEventType())
	{
		PlayerDeathEvent* pPlayerDeathEvent = static_cast<PlayerDeathEvent*>(pEvent);
		Player* pPlayer = pPlayerDeathEvent->GetPlayer();

		auto it = std::find(m_Players.begin(), m_Players.end(), pPlayer);
		m_Players.erase(it);

		delete pPlayer;
	}

	if (pEvent->GetType() == RestartGameEvent::GetStaticEventType())
	{
		RestartGameEvent* pRestartGameEvent = static_cast<RestartGameEvent*>(pEvent);
		
		player = new Player("Player", Vector2(5, 5), m_pPlayerController, m_pMeshHuman, m_pShader, Vector4::Green(), this);
		m_Players.push_back(player);
	}
}

void Game::StartFrame(float deltaTime)
{
	m_pImGuiManager->StartFrame(deltaTime);
	m_pPlayerController->StartFrame();
	m_pEventManager->DispatchAllEvents(this);
}

void Game::Update(float deltaTime)
{
	{
		//ImGui::ShowDemoWindow();
		//ImGui::SliderFloat("Number of Sides ", &numberOfSides, 3.0f, 100.0f, "%.0f");
		//ImGui::SliderFloat("Radius ", &m_Radius, 2.0f, 5.0f, "%.2f");

		/*if (ImGui::Checkbox("VSync", &m_VSyncEnabled))
		{
			wglSwapInterval(m_VSyncEnabled ? 1 : 0);
		}*/
	}

	for (Enemy* pEnemy : m_ActiveEnemies)
	{
		pEnemy->Update(deltaTime);
	}

	if (gameState == Running)
	{
		for (Player* pPlayer : m_Players)
		{
			pPlayer->Update(deltaTime);
		}

		SpawnEnemies(deltaTime);
		HandleLevels(deltaTime);
		DeleteEnemies();
		HandlePlayerLoss();
	}
	else if (gameState == Loss)
	{
		if (m_pPlayerController->IsHeld(PlayerController::Mask::Restart))
		{
			gameState = Running;
			currentLevel = Level1;
			m_pEventManager->AddEvent(new RestartGameEvent(player));
			m_LevelTimer = 0;
		}
	}
	else if (gameState == Win)
	{
		m_WinTimer += deltaTime;
		if (m_WinTimer >= 3.0f)
		{
			if (currentLevel == Level1)
			{
				currentLevel = Level2;
				gameState = Running;
			}
			else if (currentLevel == Level2)
			{
				currentLevel = Level3;
				gameState = Running;
			}
		}
	}
}

void Game::Draw()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	for (fw::GameObject* pObject : m_Objects)
	{
		glLineWidth(10);
		pObject->Draw();
	}

	for (Player* pPlayer : m_Players)
	{
		glPointSize(10);
		pPlayer->Draw();
	}

	for (int i = 0; i < m_ActiveEnemies.size(); i++)
	{
		glPointSize(20);
		m_ActiveEnemies[i]->Draw();
	}

	m_pImGuiManager->EndFrame();
}

void Game::HandleLevels(float deltaTime)
{
	m_LevelTimer += deltaTime;
	if (currentLevel == Level1)
	{
		ImGui::Text("LEVEL 1");
		if (m_LevelTimer >= 5.0f)
		{
			gameState = Win;
			m_LevelTimer = 0;
		}
	}
	else if (currentLevel == Level2)
	{
		ImGui::Text("LEVEL 2");
		if (m_LevelTimer >= 7.0f)
		{
			gameState = Win;
			m_LevelTimer = 0;
		}
	}
	else if (currentLevel == Level3)
	{
		ImGui::Text("LEVEL 3");
	}
}

void Game::SpawnEnemies(float deltaTime)
{
	timePassed += deltaTime;
	if (timePassed >= (rand() % 2) + 0.8f)
	{
		m_pEventManager->AddEvent(new SpawnEnemiesEvent());
		timePassed = 0;
	}
}

void Game::DeleteEnemies()
{
	for (auto it = m_ActiveEnemies.begin(); it != m_ActiveEnemies.end(); it++)
	{
		Enemy* enemy = *it;

		if (enemy->GetPosition().Distance(enemy->GetInitialPosition()) >= (m_Radius * 2.0f))
		{
			m_pEventManager->AddEvent(new DeleteEnemiesEvent(enemy));
		}
	}
}

void Game::HandlePlayerLoss()
{
	for (auto it = m_ActiveEnemies.begin(); it != m_ActiveEnemies.end(); it++)
	{
		Enemy* enemy = *it;

		if (player->GetPosition().Distance(enemy->GetPosition()) <= 0.25f)
		{
			m_pEventManager->AddEvent(new PlayerDeathEvent(player));
			gameState = Loss;
		}
	}
}
