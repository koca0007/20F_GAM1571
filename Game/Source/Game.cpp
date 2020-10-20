#include "GamePCH.h"

#include "Game.h"
#include "../../Framework/Libraries/imgui/imgui.h"
#include "Objects/Player.h"
#include "Objects/Shapes.h"
#include "Events/GameEvents.h"
#include "Objects/PlayerController.h"
#include "Objects/Enemy.h"


Game::Game(fw::FWCore* pFramework) : fw::GameCore(pFramework)
{
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
}

void Game::Init()
{
	m_pImGuiManager = new fw::ImGuiManager(m_pFramework);
	m_pImGuiManager->Init();

	m_pEventManager = new fw::EventManager();

	m_pShader = new fw::ShaderProgram("Data/Basic.vert", "Data/Basic.frag");

	m_pMeshHuman = new fw::Mesh();
	m_pMeshHuman->CreateShape(meshPrimType_Human, meshNumVerts_Human, meshAttribs_Human);

	m_pMeshAnimal = new fw::Mesh();
	m_pMeshAnimal->CreateShape(meshPrimType_Enemy, meshNumVerts_Enemy, meshAttribs_Enemy);

	//Circle
	radius = 4.0f;
	numberOfSides = 50;
	m_Circle = new fw::Mesh();
	
	m_Objects.push_back(new fw::GameObject("Circle", Vector2(5, 5), m_Circle, m_pShader, Vector4(1, 0, 0, 1), this));
	
	m_pPlayerController = new PlayerController();

	//Player
	player = new Player("Player", Vector2(5, 5), m_pPlayerController, m_pMeshHuman, m_pShader, Vector4(0, 1, 0, 1), this);
	m_Players.push_back(player);
}

void Game::OnEvent(fw::Event* pEvent)
{
	m_pPlayerController->OnEvent(pEvent);

	// Process the event.
	if ( pEvent->GetType() == RemoveFromGameEvent::GetStaticEventType() )
	{
		RemoveFromGameEvent* pRemoveFromGameEvent = static_cast<RemoveFromGameEvent*>(pEvent);
		fw::GameObject* pObject = pRemoveFromGameEvent->GetGameObject();

		// Remove object from list
		auto it = std::find(m_Objects.begin(), m_Objects.end(), pObject);
		m_Objects.erase(it);

		delete pObject;
	}

	if (pEvent->GetType() == SpawnEnemiesEvent::GetStaticEventType())
	{
		float pi = 3.14159265358979323846;
		float angle = (rand() % 360) / 1.0f;
		angle *= (pi / 180.0f);

		float x = radius * cosf(angle) + 5.0f;
		float y = radius * sinf(angle) + 5.0f;

		Enemy* enemy = new Enemy("Enemy", Vector2(x, y), m_pMeshHuman, m_pShader, Vector4(0, 0, 1, 1), this, player);
		m_ActiveEnemies.push_back(enemy);
	}

	if (pEvent->GetType() == DeleteEnemiesEvent::GetStaticEventType())
	{
		DeleteEnemiesEvent* pSpawnEnemiesEvent = static_cast<DeleteEnemiesEvent*>(pEvent);
		Enemy* pEnemy = pSpawnEnemiesEvent->GetEnemy();

		auto it = std::find(m_ActiveEnemies.begin(), m_ActiveEnemies.end(), pEnemy);
		m_ActiveEnemies.erase(it);

		delete pEnemy;
	}
}

void Game::Update(float deltaTime)
{
	m_pImGuiManager->StartFrame(deltaTime);
	ImGui::ShowDemoWindow();
	m_pEventManager->DispatchAllEvents(this);

	m_Circle->CreateCircle(GL_LINE_LOOP, radius, (unsigned int)numberOfSides);
	ImGui::SliderFloat("Number of Sides ", &numberOfSides, 3.0f, 100.0f, "%.0f");

	for (Player* pPlayer : m_Players)
	{
		pPlayer->Update(deltaTime);

		ImGui::Text( "x: %f", pPlayer->GetPosition().x);
		ImGui::Text("y: %f", pPlayer->GetPosition().y);
	}
	
	for (Enemy* pEnemy : m_ActiveEnemies)
	{
		pEnemy->Update(deltaTime);
	}

	timePassed += deltaTime;
	if (timePassed >= 1.0f)
	{
		m_pEventManager->AddEvent(new SpawnEnemiesEvent());
		timePassed = 0;
	}
		
	// Delete when the enemy[i] is out of bounds
	for (auto it = m_ActiveEnemies.begin(); it!= m_ActiveEnemies.end(); it++)
	{
		Enemy* go = *it;
		if (go->GetPosition().Distance(go->GetInitialPosition()) >= (radius * 2.0f) + 0.25f)
		{
			m_pEventManager->AddEvent(new DeleteEnemiesEvent(go));
		}
	}		
	
	//Enable/Disable VSync
	if (ImGui::Checkbox("VSync", &m_VSyncEnabled))
	{
		wglSwapInterval(m_VSyncEnabled ? 1 : 0);
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
	glPointSize(20);

	

	for (int i = 0; i < m_ActiveEnemies.size(); i++)
	{
		m_ActiveEnemies[i]->Draw();
	}

	m_pImGuiManager->EndFrame();
}

bool Game::IsOutOfBounds()
{
	for (int i = 0; i < m_ActiveEnemies.size(); i++)
	{
		if (m_ActiveEnemies[i]->m_Position.x < 0 || m_ActiveEnemies[i]->m_Position.x > 10
			|| m_ActiveEnemies[i]->m_Position.y < 0 || m_ActiveEnemies[i]->m_Position.y > 10)
		{
			return true;
		}
	}
	return false;
}
