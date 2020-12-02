#pragma once

#include "../../Framework/Source/Objects/GameObject.h"

class Player;

class Bomb : public fw::GameObject
{
public:

	Bomb(std::string name, Vector2 position, fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Texture* pTexture, 
													fw::Vector4 color, fw::GameCore* gameCore, Player* player, Vector2 pObjectScale);
	~Bomb();

	virtual void Update(float DeltaTime) override;

	Player* m_Player;
	float m_Alpha;

private:
	void ChangeAlpha(float DeltaTime);
};

