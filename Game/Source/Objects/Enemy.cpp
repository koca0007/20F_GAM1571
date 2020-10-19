#include "GamePCH.h"
#include "Enemy.h"
#include "Player.h"


Enemy::Enemy(std::string name, Vector2 position, fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Vector4 color, fw::GameCore* gameCore, Player* player)
	: fw::GameObject(name, position, mesh, shader, color, gameCore)
{
	m_Player = player;
	framework = m_GameCore->GetFramework();
	direction = m_Player->GetPosition() - GetPosition();
	
	m_Speed = ((rand() % 7) + 4) / 1.5f;
}

Enemy::~Enemy()
{

}

void Enemy::Update(float DeltaTime)
{
	MoveTo(DeltaTime);
}

void Enemy::MoveTo(float DeltaTime)
{
	if (m_Player != nullptr)
	{
		m_Position += direction.Normalized() * m_Speed * DeltaTime;
	}
}

void Enemy::Reset()
{
	direction = m_Player->GetPosition() - GetPosition();
	m_Speed = rand() % 1 + 0.35f;
	m_Position = Vector2(rand() % 5, rand() % 5);
}
