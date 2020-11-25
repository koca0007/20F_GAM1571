#pragma once

#include "../../Framework/Source/Objects/GameObject.h"


class Mesh;
class ShaderProgram;
class GameCore;
class PlayerController;
class SpriteSheet;

class Player : public fw::GameObject
{
public:

	Player(std::string name, Vector2 pPosition, PlayerController* pPlayerController, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, Vector4 color, fw::GameCore* pGameCore);
	virtual ~Player() override;

	virtual void Update(float DeltaTime) override;
	void ApplyMovement(float delta);

	float GetSpeed() { return m_Speed; }
	void SetSpeed(float newSpeed) { m_Speed = newSpeed; }

	void ApplyAnim(std::string animName, int maxIndex);

public:
	Vector2 spawnLoc;
	fw::SpriteSheet* spriteSheet;

protected:
	fw::FWCore* framework;
	float m_Speed;
	Vector2 lastPos;	
	PlayerController* m_pPlayerController = nullptr;
	int animIndex = 1;
	int maxAnimIndex = 3;
	float animTimer = 0;
};
