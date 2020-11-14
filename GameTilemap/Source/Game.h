
#pragma once

#include "../../Framework/Source/Objects/GameObject.h"

class PlayerController;
class Player;
class Enemy;
class Bomb;

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

protected:
	bool m_VSyncEnabled = true;

	fw::ImGuiManager* m_pImGuiManager = nullptr;
	fw::GameCore* m_GameCore = nullptr;

	Player* m_Player;
	PlayerController* m_pPlayerController = nullptr;

	std::map<std::string, fw::ShaderProgram*> m_pShaders;
	std::map<std::string, fw::Mesh*> m_pMeshes;
	std::map<std::string, fw::Texture*> m_pTextures;

	std::vector<Player*> m_Players;
	std::vector<fw::GameObject*> m_Objects;
};