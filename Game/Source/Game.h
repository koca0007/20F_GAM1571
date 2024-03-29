
#pragma once

#include "../../Framework/Source/Objects/GameObject.h"

class PlayerController;
class Player;
class Enemy;
class Bomb;

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
	void HandleGameStates(float deltaTime);
	void SpawnEnemies(float deltaTime);
	void DeleteEnemies();
	void HandlePlayerLoss();
	void ResetPlayer();
	void SpawnBombs(float deltaTime);
	void BombExplode(float deltaTime);
	void DeleteBombs();

public:
	float m_Radius;
	bool bDrawInnerCircle;
	float m_InnerRadius;

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
	float m_BombTimer = 0;

	float explosionSize = 0;

	fw::ImGuiManager* m_pImGuiManager = nullptr;
	fw::ShaderProgram* m_pShader = nullptr;
	fw::Mesh* m_pMeshHuman = nullptr;
	fw::Mesh* m_BombMesh = nullptr;
	fw::Mesh* m_ExplosionMesh = nullptr;
	fw::GameCore* m_GameCore = nullptr;
	fw::Mesh* m_Circle = nullptr;
	fw::Mesh* m_InnerCircleMesh = nullptr;
	fw::Mesh* m_PlayerMesh = nullptr;
	fw::GameObject* m_InnerCircle = nullptr;

	Player* m_Player;
	PlayerController* m_pPlayerController = nullptr;

	//Vectors
	std::vector<Player*> m_Players;
	std::vector<fw::GameObject*> m_Objects;
	std::vector<Enemy*> m_ActiveEnemies;
	std::vector<Bomb*> m_Bombs;
	std::vector<fw::GameObject*> m_Explosions;
};