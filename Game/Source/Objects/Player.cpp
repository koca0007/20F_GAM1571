#include "GamePCH.h"

#include "Player.h"
#include "../../Framework/Libraries/imgui/imgui.h"


Player::Player(std::string name, Vector2 pPosition, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore)
	: fw::GameObject(name, pPosition, pMesh, pShader, pGameCore)
{
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


	/*if (ImGui::Button("Move Right"))
	{
		Vector2 a = Vector2(1, 0);
		m_Position += a;
	}
	if (ImGui::Button("Move Left"))
	{
		m_Position += Vector2(-1, 0);
	}*/

	m_Position += dir * m_Speed * delta;


}