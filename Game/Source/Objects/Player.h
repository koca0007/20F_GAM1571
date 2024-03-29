#pragma once

#include "../../Framework/Source/Objects/GameObject.h"


class Mesh;
class ShaderProgram;
class GameCore;
class PlayerController;

class Player : public fw::GameObject
{
public:

	Player(std::string name, Vector2 pPosition, PlayerController* pPlayerController, fw::Mesh* pMesh, fw::ShaderProgram* pShader, Vector4 color, fw::GameCore* pGameCore, Vector2 pObjectScale);
	virtual ~Player();

	virtual void Update(float DeltaTime) override;
	void ApplyMovement(float delta);

	float GetSpeed() { return m_Speed; }
	void SetSpeed(float newSpeed) { m_Speed = newSpeed; }

public:
	Vector2 spawnLoc;

protected:
	fw::FWCore* framework;
	float m_Speed;
	Vector2 lastPos;
	
	PlayerController* m_pPlayerController = nullptr;
};