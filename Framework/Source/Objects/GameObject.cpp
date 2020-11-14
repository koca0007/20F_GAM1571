#include "FrameworkPCH.h"

#include "GameObject.h"
#include "Mesh.h"
#include "Core/FWCore.h"
#include "Core/GameCore.h"

namespace fw {

	GameObject::GameObject()
	{

	}

	GameObject::GameObject(std::string name, Vector2 pos, Mesh* pMesh, ShaderProgram* pShader, fw::Texture* pTexture, Vector4 color, GameCore* pGameCore)
	{
		m_Name = name;
		m_Position = pos;
		m_pMesh = pMesh;
		m_pShader = pShader;
		m_GameCore = pGameCore;
		m_pTexture = pTexture;
		m_Color = color;
	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update(float DeltaTime)
	{
		
	}

	void GameObject::Draw()
	{
		m_pMesh->Draw(m_Position, m_pShader, m_pTexture, m_Color);
	}

	std::string GameObject::GetName()
	{
		return m_Name;
	}

} // namespace fw