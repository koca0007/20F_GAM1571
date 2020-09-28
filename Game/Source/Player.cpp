#include "Framework.h"

#include "Player.h"
#include "Math/Vector.h"


Player::Player(fw::Vector2 pPosition, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore)
	: fw::GameObject(pPosition, pMesh, pShader, pGameCore)
{
	m_Position = pPosition;
	m_Shader = pShader;
	m_GameCore = pGameCore;
	m_Mesh = pMesh;

	framework = m_GameCore->GetFramework();
}

Player::~Player()
{

}

void Player::Update(float DeltaTime)
{
	ApplyMovement(DeltaTime);
}

void Player::ApplyMovement(float delta) 
{
	float speed = 2.f;
	
	if (framework->IsKeyDown('D')) // d
	{
		position.x += speed * delta;
	}
	if (framework->IsKeyDown('A')) // a
	{
		position.x -= speed * delta;
	}
	if (framework->IsKeyDown('W')) // w
	{
		position.y += speed * delta;
	}
	if (framework->IsKeyDown('S')) // s
	{
		position.y -= speed * delta;
	}
}

void Player::Draw()
{
	m_Mesh->Draw(position, m_Shader);
}
