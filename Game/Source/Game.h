
#pragma once

#include "../../Framework/Source/Objects/GameObject.h"

class PlayerController;
class Player;
class Enemy;

enum Levels
{
	Main,
	Level1,
	Level2,
	Level3,
};

enum GameStates
{
	Null,
	Running,
	Loss,
	Win,
	Victory
};

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

	void HandleLevels(float deltaTime);
	void SpawnEnemies(float deltaTime);
	void DeleteEnemies();
	void HandlePlayerLoss();
	void ResetPlayer();

public:
	float m_Radius;

protected:
	float numberOfSides;
	bool m_VSyncEnabled = true;

	float timeToSpawn = 4;
	float timePassed = 0;

	//Level States
	Levels currentLevel;
	GameStates gameState;
	float m_LevelTimer;
	float m_WinTimer;

	fw::ImGuiManager* m_pImGuiManager = nullptr;
	fw::ShaderProgram* m_pShader = nullptr;
	fw::Mesh* m_pMeshHuman = nullptr;
	fw::Mesh* m_pMeshAnimal = nullptr;
	fw::Mesh* m_Circle = nullptr;
	fw::GameCore* m_GameCore = nullptr;

	Player* player;
	PlayerController* m_pPlayerController = nullptr;

	//Vectors
	std::vector<Player*> m_Players;
	std::vector<fw::GameObject*> m_Objects;
	std::vector<Enemy*> m_ActiveEnemies;
};