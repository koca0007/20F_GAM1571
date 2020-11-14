#include "GamePCH.h"

#include "Player.h"
#include "Objects/PlayerController.h"
#include "Game.h"


Player::Player(std::string name, Vector2 pPosition, PlayerController* pPlayerController, fw::Mesh* pMesh, fw::ShaderProgram* pShader, 
																fw::Texture* pTexture, Vector4 color, fw::GameCore* pGameCore)
	: fw::GameObject(name, pPosition, pMesh, pShader, pTexture, color, pGameCore)
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
	
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Up)) 
	{ 
		dir.y = 1; 
	}
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Down))
	{
		dir.y = -1;
	}
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Left))
	{
		dir.x = -1;
	}
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Right))
	{
		dir.x = 1;
	}

	dir.Normalize();
	m_Position += dir * m_Speed * delta;
}