#pragma once

#include "Objects/GameObject.h"


class Mesh;
class ShaderProgram;
class GameCore;

class Player : public fw::GameObject
{
public:

	Player(fw::Vector2 position, fw::Mesh* mesh, fw::ShaderProgram* shader, fw::GameCore* gameCore);
	~Player();

	void Update(float DeltaTime);
	void ApplyMovement(float delta);
	void Draw();

	fw::Vector2 m_Position;
	fw::ShaderProgram* m_Shader;
	fw::Mesh* m_Mesh;
	fw::GameCore* m_GameCore;

	fw::FWCore* framework;
	
};