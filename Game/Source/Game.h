
#pragma once

#include "../../Framework/Source/Objects/GameObject.h"



class Game : public fw::GameCore
{
public:
	Game(fw::FWCore* pFramework);
	virtual ~Game();

	void Init();
	
	virtual void OnEvent(fw::Event* pEvent) override;
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

protected:
	fw::ImGuiManager* m_pImGuiManager = nullptr;
	fw::EventManager* m_pEventManager = nullptr;

	fw::ShaderProgram* m_pShader = nullptr;
	fw::Mesh* m_pMeshHuman = nullptr;
	fw::Mesh* m_pMeshAnimal = nullptr;
	fw::Mesh* m_Circle = nullptr;
	fw::GameCore* m_GameCore;

	class Player* player;

	std::vector<Player*> m_Players;
	std::vector<fw::GameObject*> m_Objects;
	
	float radius;
	float numberOfSides;

	Vector2 vec2;
};