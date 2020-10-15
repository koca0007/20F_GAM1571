#pragma once

#include "../../Framework/Source/Objects/GameObject.h"


class Player;

class Enemy : public fw::GameObject
{
public:

	Enemy(std::string name, Vector2 position, fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Vector4 color, fw::GameCore* gameCore, Player* player);
	~Enemy();

	virtual void Update(float DeltaTime) override;

	void MoveTo(float DeltaTime);

	bool IsInUse() { return GetPosition().x < 10 || GetPosition().x > 0 || GetPosition().y < 10 || GetPosition().y > 0; }

	float GetSpeed() { return m_Speed; }
	void SetSpeed(float newSpeed) { m_Speed = newSpeed; }

protected:
	Player* m_Player;
	fw::FWCore* framework;
	bool bMoving = false;
	Vector2 playerPosition;
	Vector2 direction;
	float m_Speed;
};