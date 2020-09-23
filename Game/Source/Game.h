#pragma once

#include "Objects/GameObject.h"

class Game : public fw::GameCore
{
	

public:
	Game(fw::FWCore* pFramework);
	virtual ~Game();

	void Init();
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

	std::vector<fw::GameObject*> gameObjects;

protected:
	fw::ShaderProgram* m_pShader = nullptr;
	fw::Mesh* m_pHumanoidMesh;
	fw::Mesh* m_pAnimal;
	fw::FWCore* m_pFramework;
	fw::ImGuiManager* GuiManager;
};