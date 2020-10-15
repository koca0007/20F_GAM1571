#pragma once

#include "../../Framework/Source/Objects/GameObject.h"


class Mesh;
class ShaderProgram;
class GameCore;

class Player : public fw::GameObject
{
public:

	Player(std::string name, Vector2 position, fw::Mesh* mesh, fw::ShaderProgram* shader, Vector4 color, fw::GameCore* gameCore);
	~Player();

	virtual void Update(float DeltaTime) override;
	void ApplyMovement(float delta);

	float GetSpeed() { return m_Speed; }
	void SetSpeed(float newSpeed) { m_Speed = newSpeed; }
	Vector2 GetStartPosition() { return m_StartPosition; }

protected:
	fw::FWCore* framework;
	float m_Speed = 2.f;
	Vector2 m_StartPosition;
};