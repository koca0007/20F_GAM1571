#include "GamePCH.h"

#include "Player.h"
#include "Objects/PlayerController.h"
#include "Game.h"


Player::Player(std::string name, Vector2 pPosition, PlayerController* pPlayerController, fw::Mesh* pMesh, fw::ShaderProgram* pShader, 
																								Vector4 color, fw::GameCore* pGameCore)
	: fw::GameObject(name, pPosition, pMesh, pShader, color, pGameCore)
{
	framework = m_GameCore->GetFramework();
	m_pPlayerController = pPlayerController;
	m_Speed = 4.0f;
	spawnLoc = pPosition;
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
	Vector2 dir = (Vector2(0, 0));

	Vector2 newLoc = m_Position - spawnLoc;

	if ((GetPosition().Distance(spawnLoc) >= 4.5f))
	{
		m_Position = newLoc.Normalized() * 4.5f + spawnLoc;
	}
	
	if (m_pPlayerController->IsUpHeld())
	{
		dir.y = 1;
	}
	if (m_pPlayerController->IsDownHeld())
	{
		dir.y = -1;
	}
	if (m_pPlayerController->IsLeftHeld())
	{
		dir.x = -1;
	}
	if (m_pPlayerController->IsRightHeld())
	{
		dir.x = 1;
	}
	
	m_Position += dir * m_Speed * delta;
}