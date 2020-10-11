#include "GamePCH.h"

#include "Game.h"
#include "../../Framework/Libraries/imgui/imgui.h"
#include "Objects/Player.h"
#include "Objects/Shapes.h"
#include "Events/GameEvents.h"


Game::Game(fw::FWCore* pFramework) : fw::GameCore(pFramework)
{
	
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
	
	//Player
	player = new Player("Player", Vector2(5,5), m_pMeshHuman, m_pShader, this);
	m_Players.push_back(player);

	

	//m_Objects.push_back(new fw::GameObject("Enemy 3", Vector2(5, 5), m_pMeshAnimal, m_pShader, this));
	//m_Objects.push_back(new fw::GameObject("Enemy 4", Vector2(1, 1), m_pMeshAnimal, m_pShader, this));
	m_Objects.push_back(new fw::GameObject("Enemy 5", Vector2(5, 5), m_pMeshAnimal, m_pShader, this));

	m_Objects.push_back(new fw::GameObject("Circle", Vector2(5, 5), m_Circle, m_pShader, this));
	
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

	}
	
}

void Game::Update(float deltaTime)
{
	m_pImGuiManager->StartFrame(deltaTime);
	ImGui::ShowDemoWindow();
	m_pEventManager->DispatchAllEvents(this);

	m_Circle->CreateCircle(GL_LINE_LOOP, radius, numberOfSides);
	ImGui::SliderFloat("Number of Sides ", &numberOfSides, 3.0f, 100.0f, "%.0f");

	for (Player* pObject : m_Players)
	{
		pObject->Update(deltaTime);
	}

	//for (fw::GameObject* pObject : m_Objects)
	for ( auto it = m_Objects.begin(); it != m_Objects.end(); it++)
	{
		fw::GameObject* pObject = *it;

		pObject->Update(deltaTime);

		ImGui::PushID(pObject);
		ImGui::Text("Name: %s", pObject->GetName().c_str());
		ImGui::SameLine();
		if (ImGui::Button("Delete"))
		{
			m_pEventManager->AddEvent( new RemoveFromGameEvent( pObject ));
		}
		ImGui::PopID();
	}

	double pi = 3.14159265358979323846;
	double area = pi * radius * radius;


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

	/*m_Circle->Draw(Vector2(5, 5), m_pShader);*/

	m_pImGuiManager->EndFrame();
}