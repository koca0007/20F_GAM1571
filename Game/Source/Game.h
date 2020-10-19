
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
	
	virtual void OnEvent(fw::Event* pEvent) override;
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;


protected:
	float radius;
	float numberOfSides;
	bool isColliding = false;
	Vector2 vec2;
	bool m_VSyncEnabled = false;

	float timeToSpawn = 4;
	float timePassed = 0;

protected:
	fw::ImGuiManager* m_pImGuiManager = nullptr;
	fw::ShaderProgram* m_pShader = nullptr;
	fw::Mesh* m_pMeshHuman = nullptr;
	fw::Mesh* m_pMeshAnimal = nullptr;
	fw::Mesh* m_Circle = nullptr;
	fw::GameCore* m_GameCore = nullptr;

	Player* player;
	Enemy* enemy1;
	Enemy* enemy2;
	Enemy* enemy3;
	Enemy* enemy4;
	Enemy* enemy5;

	PlayerController* m_pPlayerController = nullptr;

	std::vector<Player*> m_Players;
	std::vector<fw::GameObject*> m_Objects;
	std::vector<Enemy*> m_ActiveEnemies;

protected:
	bool IsOutOfBounds();
};