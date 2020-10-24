
#pragma once

#include "../../Framework/Source/Objects/GameObject.h"

class PlayerController;
class Player;
class Enemy;

class Game : public fw::GameCore
{
public:
	Game(fw::FWCore* pFramework);
	virtual ~Game();

	void Init();
	
	virtual void StartFrame(float deltaTime) override;
	virtual void OnEvent(fw::Event* pEvent) override;
	
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

	float m_Radius;
protected:
	
	float numberOfSides;
	bool isColliding = false;
	Vector2 vec2;
	bool m_VSyncEnabled = false;

	float timeToSpawn = 4;
	float timePassed = 0;

	int health = 2;
	bool bGameOver = false;

protected:
	fw::ImGuiManager* m_pImGuiManager = nullptr;
	fw::ShaderProgram* m_pShader = nullptr;
	fw::Mesh* m_pMeshHuman = nullptr;
	fw::Mesh* m_pMeshAnimal = nullptr;
	fw::Mesh* m_Circle = nullptr;
	fw::GameCore* m_GameCore = nullptr;

	Player* player;

	PlayerController* m_pPlayerController = nullptr;

	std::vector<Player*> m_Players;
	std::vector<fw::GameObject*> m_Objects;
	std::vector<Enemy*> m_ActiveEnemies;
};