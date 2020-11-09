#include "GamePCH.h"
#include "Bomb.h"

Bomb::Bomb(std::string name, Vector2 position, fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Vector4 color, fw::GameCore* gameCore, Player* player)
	: fw::GameObject(name, position, mesh, shader, color, gameCore)
{
	m_Player = player;
	m_Alpha = 1;
	
}

Bomb::~Bomb()
{

}

void Bomb::Update(float DeltaTime)
{
	ChangeAlpha(DeltaTime);
}

void Bomb::ChangeAlpha(float DeltaTime)
{
	SetAlpha(m_Alpha);

	m_Alpha -= DeltaTime;
	if (m_Alpha <= 0)
	{
		m_Alpha = 1;
	}
}
