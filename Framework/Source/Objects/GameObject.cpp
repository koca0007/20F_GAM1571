#include "FrameworkPCH.h"

#include "GameObject.h"
#include "Mesh.h"
#include "Core/FWCore.h"
#include "Core/GameCore.h"

namespace fw {

	GameObject::GameObject(Vector2 pVec2, Mesh* pMesh, ShaderProgram* pShader, GameCore* pGameCore)
	{
		position = pVec2;

		m_pMesh = pMesh;
		m_pShader = pShader;
		m_GameCore = pGameCore;
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		
	}

	void GameObject::Draw()
	{
		/*m_pMesh->Draw(position, m_pShader);*/
	}
} // namespace fw