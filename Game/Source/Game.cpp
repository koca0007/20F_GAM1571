#include "GamePCH.h"

#include "Game.h"
#include "../../Framework/Libraries/imgui/imgui.h"
#include "Objects/Player.h"
#include "Objects/Shapes.h"
#include "Events/GameEvents.h"
#include "Objects/Enemy.h"


Game::Game(fw::FWCore* pFramework) : fw::GameCore(pFramework)
{
	isEnemyDead = false;
}

Game::~Game()
{
	delete m_pShader;
	delete m_pMeshHuman;
	delete m_pMeshAnimal;
	delete m_Circle;

	for (Player* pObject : m_Players)
	{
		delete pObject;
	}

	delete m_pImGuiManager;
	delete m_pEventManager;
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
	radius = 4.5f;
	numberOfSides = 50;
	m_Circle = new fw::Mesh();
	glLineWidth(9);
	m_Objects.push_back(new fw::GameObject("Circle", Vector2(5, 5), m_Circle, m_pShader, Vector4(1, 0, 0, 1), this));
	
	//Player
	player = new Player("Player", Vector2(5,5), m_pMeshHuman, m_pShader, Vector4(0, 1, 0, 1), this);
	m_Players.push_back(player);
	

	//m_Objects.push_back(new fw::GameObject("Enemy 3", Vector2(5, 5), m_pMeshAnimal, m_pShader, this));
	//m_Objects.push_back(new fw::GameObject("Enemy 4", Vector2(1, 1), m_pMeshAnimal, m_pShader, this));

	enemy = new Enemy("Enemy", Vector2(8, 8), m_pMeshHuman, m_pShader, Vector4(0, 0, 1, 1), this, player);
	m_Enemies.push_back(enemy);

	enemy->SetSpeed(0.5f);
}

void Game::OnEvent(fw::Event* pEvent)
{
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
		isEnemyDead = false;

		SpawnEnemiesEvent* pSpawnEnemiesEvent = static_cast<SpawnEnemiesEvent*>(pEvent);
		
		// HERE
		auto it = std::find(m_Enemies.begin(), m_Enemies.end(), enemy);
		
	}

	if (pEvent->GetType() == DeleteEnemiesEvent::GetStaticEventType())
	{
		isEnemyDead = false;

		DeleteEnemiesEvent* pSpawnEnemiesEvent = static_cast<DeleteEnemiesEvent*>(pEvent);
		fw::GameObject* pObject = pSpawnEnemiesEvent->GetGameObject();
	}

	
}

void Game::Update(float deltaTime)
{
	m_pImGuiManager->StartFrame(deltaTime);
	ImGui::ShowDemoWindow();
	m_pEventManager->DispatchAllEvents(this);

	m_Circle->CreateCircle(GL_LINE_LOOP, radius, numberOfSides);
	ImGui::SliderFloat("Number of Sides ", &numberOfSides, 3.0f, 100.0f, "%.0f");

	for (Player* pPlayer : m_Players)
	{
		pPlayer->Update(deltaTime);
	}

	for (Enemy* pEnemy : m_Enemies)
	{
		pEnemy->Update(deltaTime);
	}

	/*m_pEventManager->AddEvent(new RemoveFromGameEvent(pObject));*/

	{
		//Enable/Disable VSync
		if (ImGui::Checkbox("V-Sync", &m_VSyncEnabled));
		{
			wglSwapInterval(m_VSyncEnabled ? 1 : 0);
		}
		
	}
}

void Game::Draw()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10);

	for (Player* pObject : m_Players)
	{
		pObject->Draw();
	}

	for (fw::GameObject* pObject : m_Objects)
	{
		pObject->Draw();
	}

	for (int i = 0; i < m_Enemies.size(); i++)
	{
		if (!isEnemyDead)
			m_Enemies[i]->Draw();
	}

	/*m_Circle->Draw(Vector2(5, 5), m_pShader);*/

	m_pImGuiManager->EndFrame();
}