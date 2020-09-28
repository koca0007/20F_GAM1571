
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

protected:
	fw::ImGuiManager* m_pImGuiManager = nullptr;

	fw::ShaderProgram* m_pShader = nullptr;
	fw::Mesh* m_pMeshHuman = nullptr;
	fw::Mesh* m_pMeshAnimal = nullptr;
	fw::GameCore* m_GameCore;

	

	class Player* player;

	std::vector<Player*> m_Objects;
	

	fw::Vector2 vec2;
};