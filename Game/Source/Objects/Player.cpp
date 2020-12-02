#include "GamePCH.h"

#include "Player.h"
#include "Objects/PlayerController.h"
#include "Game.h"


Player::Player(std::string name, Vector2 pPosition, PlayerController* pPlayerController, fw::Mesh* pMesh, fw::ShaderProgram* pShader, 
																								Vector4 color, fw::GameCore* pGameCore, Vector2 pObjectScale)
	: fw::GameObject(name, pPosition, pMesh, pShader, nullptr, color, pGameCore, pObjectScale)
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
	Game* game = static_cast<Game*>(m_GameCore);
	Vector2 newLoc = m_Position - spawnLoc;

	if (!game->bDrawInnerCircle)
	{
		if ((GetPosition().Distance(spawnLoc) >= game->m_Radius))
		{
			m_Position = newLoc.Normalized() * game->m_Radius + spawnLoc;
		}
	}
	else
	{
		if ((GetPosition().Distance(spawnLoc) >= game->m_InnerRadius))
		{
			m_Position = newLoc.Normalized() * game->m_InnerRadius + spawnLoc;
		}
	}
	
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