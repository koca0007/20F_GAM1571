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

	m_UVScale.Set(Vector2(64.0f / 1024.0f, 64.0f / 512.0f));
	m_UVOffset.Set(Vector2(780.0f / 1024.0f, 383.0f / 512.0f));
}

Player::~Player()
{

}

void Player::Update(float DeltaTime)
{
	ApplyMovement(DeltaTime);

	// Display player walk down frame 1
}

void Player::ApplyMovement(float delta) 
{
	Vector2 dir = (Vector2(0, 0));

	if (m_pPlayerController->IsHeld(PlayerController::Mask::Up)) 
	{ 
		dir.y = 1;
		i += delta;
		if (i >= 0.10f && i <= 0.20f)
		{
			m_UVOffset.Set(Vector2(845.0f / 1024.0f, 448.0f / 512.0f));
		}
		if (i > 0.2f && i <= 0.30f)
		{
			m_UVOffset.Set(Vector2(520.0f / 1024.0f, 58.0f / 512.0f));
		}
		if (i > 0.3f)
		{
			m_UVOffset.Set(Vector2(585.0f / 1024.0f, 123.0f / 512.0f));
			i = 0;
		}
	}
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Down))
	{
		dir.y = -1;
		i += delta;
		if (i >= 0.10f && i <= 0.20f)
		{
			m_UVOffset.Set(Vector2(650.0f / 1024.0f, 188.0f / 512.0f));
		}
		if (i > 0.2f && i <= 0.30f)
		{
			m_UVOffset.Set(Vector2(715.0f / 1024.0f, 253.0f / 512.0f));
		}
		if (i > 0.3f)
		{
			m_UVOffset.Set(Vector2(780.0f / 1024.0f, 318.0f / 512.0f));
			i = 0;
		}
	}
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Left))
	{
		dir.x = -1;
		i += delta;
		if (i >= 0.10f && i <= 0.20f)
		{
			m_UVOffset.Set(Vector2(845.0f / 1024.0f, 318.0f / 512.0f));
		}
		if (i > 0.2f && i <= 0.30f)
		{
			m_UVOffset.Set(Vector2(910.0f / 1024.0f, 383.0f / 512.0f));
		}
		if (i > 0.3f)
		{
			m_UVOffset.Set(Vector2(650.0f / 1024.0f, 58.0f / 512.0f));
			i = 0;
		}
	}
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Right))
	{
		dir.x = 1;
		i += delta;
		if (i >= 0.10f && i <= 0.20f)
		{
			m_UVOffset.Set(Vector2(650.0f / 1024.0f, 123.0f / 512.0f));
		}
		if (i > 0.2f && i <= 0.30f)
		{
			m_UVOffset.Set(Vector2(715.0f / 1024.0f, 188.0f / 512.0f));
		}
		if (i > 0.3f)
		{
			m_UVOffset.Set(Vector2(780.0f / 1024.0f, 253.0f / 512.0f));
			i = 0;
		}
		
	}

	dir.Normalize();
	m_Position += dir * m_Speed * delta;
}