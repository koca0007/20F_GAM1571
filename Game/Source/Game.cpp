#include "Framework.h"

#include "Game.h"
#include "../Libraries/imgui/imgui.h"
#include "Player.h"
#include "Math/Vector.h"


Game::Game(fw::FWCore* pFramework) : fw::GameCore(pFramework)
{
	
}

Game::~Game()
{
	delete m_pShader;
	delete m_pMeshHuman;
	delete m_pMeshAnimal;

	for (fw::GameObject* pObject : m_Objects)
	{
		delete pObject;
	}

	delete m_pImGuiManager;
}

void Game::Init()
{
	m_pImGuiManager = new fw::ImGuiManager(m_pFramework);
	m_pImGuiManager->Init();

	

	m_pShader = new fw::ShaderProgram("Data/Basic.vert", "Data/Basic.frag");

	// Define our triangle as 3 positions.
	float attribsHuman[] =
	{
		0.0f, 0.7f, // Center
		0.2f, 0.7f, // Top right
		0.1f, 0.5f, // right center
		0.0f, .6f, // right center
		0.2f, 0.6f,
		.1f, .2f,
		.05f, .3f,
		0.15f, .3f,
		0.1f, 0.0f
	};

	m_pMeshHuman = new fw::Mesh();
	m_pMeshHuman->CreateShape(GL_TRIANGLES, 9, &attribsHuman[0]);

	float attribsAnimal[] =
	{
		-0.0f,  0.0f, // Center
		-0.5f,  0.5f, // Top right
		-0.5f,  0.0f, // Right center
		-0.5f, -0.5f, // Right bottom
	};

	m_pMeshAnimal = new fw::Mesh(GL_LINES, 4, &attribsAnimal[0]);
	
	player = new Player(fw::Vector2(9,5), m_pMeshHuman, m_pShader, this);


	m_Objects.push_back(player);
	//m_Objects.push_back(new Player(fw::Vector2(0,0), m_pMeshAnimal, m_pShader, gameCore));
}

void Game::Update(float deltaTime)
{
	m_pImGuiManager->StartFrame(deltaTime);
	ImGui::ShowDemoWindow();
	
	for (Player* pObject : m_Objects)
	{
		pObject->Update(deltaTime);
	}
}

void Game::Draw()
{
	glClearColor(0, 1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10);

	for (Player* pObject : m_Objects)
	{
		pObject->Draw();
	}

	m_pImGuiManager->EndFrame();
}