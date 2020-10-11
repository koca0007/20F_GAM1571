#include "FrameworkPCH.h"

#include "GameObject.h"
#include "Mesh.h"
#include "Core/FWCore.h"
#include "Core/GameCore.h"

namespace fw {

	GameObject::GameObject()
	{

	}

	GameObject::GameObject(std::string name, Vector2 pos, Mesh* pMesh, ShaderProgram* pShader, GameCore* pGameCore)
	{
		m_Name = name;
		m_Position = pos;
		m_pMesh = pMesh;
		m_pShader = pShader;
		m_GameCore = pGameCore;
	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update(float DeltaTime)
	{
		
	}

	void GameObject::Draw()
	{
		m_pMesh->Draw(m_Position, m_pShader);
	}

	std::string GameObject::GetName()
	{
		return m_Name;
	}

} // namespace fw