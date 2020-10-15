#include "GamePCH.h"
#include "Enemy.h"
#include "Player.h"


Enemy::Enemy(std::string name, Vector2 position, fw::Mesh* mesh, fw::ShaderProgram* shader, fw::Vector4 color, fw::GameCore* gameCore, Player* player)
	: fw::GameObject(name, position, mesh, shader, color, gameCore)
{
	m_Player = player;
	framework = m_GameCore->GetFramework();
	direction = m_Player->GetPosition() - GetPosition();
	
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
	if (m_Player != nullptr && !bMoving)
	{
		m_Position += direction * DeltaTime* m_Speed;
	}
}
