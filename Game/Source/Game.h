#pragma once

#include "GameObject.h"

class Game : public fw::GameCore
{
public:
	Game();
	virtual ~Game();

	void Init();
	virtual void Update() override;
	virtual void Draw() override;

	std::vector<fw::GameObject*> gameObjects;

protected:
	fw::ShaderProgram* m_pShader = nullptr;
	fw::Mesh* m_pHumanoidMesh;
	fw::Mesh* m_pAnimal;

	
};