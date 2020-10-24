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

	float radius = static_cast<Game*>(m_GameCore)->m_Radius;
	{
		Vector2 newLoc = m_Position - spawnLoc;
		if ((GetPosition().Distance(spawnLoc) >= radius))
		{
			m_Position = newLoc.Normalized() * radius + spawnLoc;
		}
	}

	if (m_pPlayerController->WasPressed(PlayerController::Mask::Up))
	{
		/*m_Position = Vector2(5, 5);*/
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