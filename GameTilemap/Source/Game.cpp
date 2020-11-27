#include "GamePCH.h"

#include "Game.h"
#include "../../Framework/Libraries/imgui/imgui.h"
#include "Objects/Player.h"
#include "Objects/Shapes.h"
#include "Events/GameEvents.h"
#include "Objects/PlayerController.h"
#include "Objects/Enemy.h"
#include "Objects/Bomb.h"
#include "../../Framework/Source/Objects/SpriteSheet.h"
#include "Tilemap/Tilemap.h"
#include "Tilemap/Layouts.h"

namespace rj = rapidjson;

Game::Game(fw::FWCore* pFramework) : fw::GameCore(pFramework)
{
	wglSwapInterval(m_VSyncEnabled ? 1 : 0);
}

Game::~Game()
{
	delete m_pPlayerController;
	delete m_pImGuiManager;
	delete m_pEventManager;
	delete m_Tilemap;

	for (Player* player : m_Players)
	{
		delete player;
	}

	for (fw::GameObject* go : m_Objects)
	{
		delete go;
	}

	for (auto pShader : m_pShaders)
	{
		delete pShader.second;
	}

	for (auto pMesh : m_pMeshes)
	{
		delete pMesh.second;
	}

	for (auto object : m_pTextures)
	{
		delete object.second;
	}

	for (auto object : m_pSpriteSheets)
	{
		delete object.second;
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
	m_pPlayerController = new PlayerController();

	m_pShaders["Basic"] = new fw::ShaderProgram("Data/Basic.vert", "Data/Basic.frag");
	m_pMeshes["Player"] = new fw::Mesh(meshPrimType_Box, meshNumVerts_Box, meshAttribs_Box);
	m_pMeshes["Tilemap"] = new fw::Mesh(meshPrimType_Sprite, meshNumVerts_Sprite, meshAttribs_Sprite);
	m_pTextures["Player"] = new fw::Texture("Data/Textures/Sokoban.png");
	m_pSpriteSheets["Sokoban"] = new fw::SpriteSheet("Data/Textures/Sokoban.json");

	m_Tilemap = new Tilemap(Level1Layout, Level1Layout_Width, Level1Layout_Height, nullptr, m_pSpriteSheets["Sokoban"], m_pMeshes["Tilemap"]);

	m_Player = new Player("Player", Vector2(5, 5), m_pPlayerController, m_pMeshes["Player"], m_pShaders["Basic"], m_pTextures["Player"], Vector4::Grey(), this);
	m_Players.push_back(m_Player);
}

void Game::OnEvent(fw::Event* pEvent)
{
	m_pPlayerController->OnEvent(pEvent);

	if ( pEvent->GetType() == RemoveFromGameEvent::GetStaticEventType() )
	{
		RemoveFromGameEvent* pRemoveFromGameEvent = static_cast<RemoveFromGameEvent*>(pEvent);
		fw::GameObject* pObject = pRemoveFromGameEvent->GetGameObject();

		auto it = std::find(m_Objects.begin(), m_Objects.end(), pObject);
		m_Objects.erase(it);

		delete pObject;
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
	ImGui::Begin("Game");

	for (Player* pPlayer : m_Players)
	{
		pPlayer->Update(deltaTime);
	}

	if (m_Player != nullptr)
	{
		ImGui::Text("PositionX %f", m_Player->GetPosition().x);
		ImGui::Text("PositionY %f", m_Player->GetPosition().y);
	}
	
	ImGui::End();
}

void Game::Draw()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	m_Tilemap->Draw();

	for (Player* pPlayer : m_Players)
	{
		pPlayer->Draw();
	}

	

	m_pImGuiManager->EndFrame();
}
