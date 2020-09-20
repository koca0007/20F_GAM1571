#include "Framework.h"

#include <GameObject.h>
#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{
	if (m_pShader != nullptr)
	{
		delete m_pShader;
	}
	if (m_pHumanoidMesh != nullptr)
	{
		delete m_pHumanoidMesh;
	}
	if (m_pAnimal != nullptr)
	{
		delete m_pAnimal;
	}
}

void Game::Update()
{

}

void Game::Init()
{
	m_pShader = new fw::ShaderProgram("Data/Basic.vert", "Data/Basic.frag");

	m_pHumanoidMesh = new fw::Mesh(m_pShader);
	m_pHumanoidMesh->MakeHumanoid();
	m_pAnimal = new fw::Mesh(m_pShader);
	m_pAnimal->MakeAnimal();

	fw::GameObject* Human = new fw::GameObject(m_pHumanoidMesh);
	fw::GameObject* Animal = new fw::GameObject(m_pAnimal);

	gameObjects.push_back(Human);
	gameObjects.push_back(Animal);
}

void Game::Draw()
{
	glClearColor(0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10);

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Draw(m_pShader);
	}
}

