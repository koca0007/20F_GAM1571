#include "GamePCH.h"

#include "Player.h"
#include "Objects/PlayerController.h"
#include "Game.h"
#include "../../Framework/Source/Objects/SpriteSheet.h"

Player::Player(std::string name, Vector2 pPosition, PlayerController* pPlayerController, fw::Mesh* pMesh, fw::ShaderProgram* pShader, 
																fw::Texture* pTexture, Vector4 color, fw::GameCore* pGameCore, Vector2 pObjectScale)
	: fw::GameObject(name, pPosition, pMesh, pShader, pTexture, color, pGameCore, pObjectScale)
{
	framework = m_GameCore->GetFramework();
	m_pPlayerController = pPlayerController;
	m_Speed = 4.0f;
	spawnLoc = pPosition;

	spriteSheet = new fw::SpriteSheet("Data/Textures/Sokoban.json");
	m_UVScale.Set(spriteSheet->GetUVScale("Player/player_01"));
	m_UVOffset = spriteSheet->GetSprite("Player/player_01").UVOffset;
}

Player::~Player()
{
	delete spriteSheet;
}

void Player::Update(float DeltaTime)
{
	ApplyMovement(DeltaTime);
}

void Player::ApplyMovement(float delta) 
{
	Vector2 dir = (Vector2(0, 0));
	
	animTimer += delta;

	//Increment animIndex at a certain interval
	if (animTimer >= 0.10f)
	{
		animTimer = 0;
		animIndex += 1;

		//Reset animIndex
		if (animIndex == maxAnimIndex + 1)
		{
			animIndex = 1;
		}
	}
	
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Up)) 
	{ 
		dir.y = 1;
		ApplyAnim("WalkUp", 3);
	}
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Down))
	{
		dir.y = -1;
		ApplyAnim("WalkDown", 3);
	}
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Left))
	{
		dir.x = -1;
		ApplyAnim("WalkLeft", 3);
	}
	if (m_pPlayerController->IsHeld(PlayerController::Mask::Right))
	{
		dir.x = 1;
		ApplyAnim("WalkRight", 3);
	}

	dir.Normalize();
	m_Position += dir * m_Speed * delta;
}

void Player::ApplyAnim(std::string animName, int maxIndex )
{
	//Declare this animation's max animation count
	maxAnimIndex = maxIndex;
	//Reset animIndex if exceeds this animation's max index
	animIndex = (animIndex > maxAnimIndex) ? 1 : animIndex;
	//Set the UVOffset according to the name of the sprite
	m_UVOffset.Set(spriteSheet->GetSprite(GetSpriteName(animName + std::to_string(animIndex))).UVOffset);
}

std::string Player::GetSpriteName(std::string animName)
{
		if (animName == "WalkUp1")  {return	"Player/player_02"; }
	else if (animName == "WalkUp2") { return "Player/player_03"; }
	else if (animName == "WalkUp3") { return "Player/player_04"; }

	else if (animName == "WalkDown1") { return "Player/player_05"; }
	else if (animName == "WalkDown2") { return "Player/player_06"; }
	else if (animName == "WalkDown3") { return "Player/player_07"; }

	else if (animName == "WalkRight1") { return "Player/player_11"; }
	else if (animName == "WalkRight2") { return "Player/player_12"; }
	else if (animName == "WalkRight3") { return "Player/player_13"; }

	else if (animName == "WalkLeft1") { return "Player/player_14"; }
	else if (animName == "WalkLeft2") { return "Player/player_15"; }
	else if (animName == "WalkLeft3") { return "Player/player_16"; }

	return "";
}

