
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
	class Enemy* enemy;

	std::vector<Player*> m_Players;
	std::vector<fw::GameObject*> m_Objects;
	std::vector<Enemy*> m_Enemies;
	
protected:
	float radius;
	float numberOfSides;
	bool isColliding;
	bool isEnemyDead;
	Vector2 vec2;
	bool m_VSyncEnabled = false;
};