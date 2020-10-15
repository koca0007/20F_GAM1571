#include "GamePCH.h"

#include "Player.h"
#include "../../Framework/Libraries/imgui/imgui.h"
#include "Game.h"


Player::Player(std::string name, Vector2 pPosition, fw::Mesh* pMesh, fw::ShaderProgram* pShader, Vector4 color, fw::GameCore* pGameCore)
	: fw::GameObject(name, pPosition, pMesh, pShader, color, pGameCore)
{
	framework = m_GameCore->GetFramework();
	m_StartPosition = pPosition;
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
	Vector2 dir;
	if (m_GameCore->GetFramework()->IsKeyDown('D'))
	{
		dir.x = 1;
	}
	if (framework->IsKeyDown('A')) 
	{
		dir.x = -1;
	}
	if (framework->IsKeyDown('W')) 
	{
		dir.y = 1;
	}
	if (framework->IsKeyDown('S')) 
	{
		dir.y = -1;
	}
	m_Position += dir * m_Speed * delta;
	

	//Deal with collision with environment
	{
		//static_cast<Game*>( m_pGameCore )->
	}
}