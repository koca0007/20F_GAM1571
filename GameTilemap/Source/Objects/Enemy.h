#pragma once

#include "../../Framework/Source/Objects/GameObject.h"


class Player;

class Enemy : public fw::GameObject
{
public:

	Enemy(std::string name, Vector2 position, fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* pTexture, fw::Vector4 color, fw::GameCore* gameCore, Player* player, Vector2 pObjectScale);
	virtual ~Enemy() override;

	virtual void Update(float DeltaTime) override;

	void MoveTo(float DeltaTime);

	Vector2 GetInitialPosition() { return initialPosition; }

protected:
	Player* m_Player;
	Vector2 playerPosition;
	Vector2 initialPosition;
	Vector2 direction;
	float m_Speed;
};