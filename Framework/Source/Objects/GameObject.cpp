#include "FrameworkPCH.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Utility/ShaderProgram.h"



namespace fw
{
	GameObject::GameObject(Mesh* mesh)
	{
		m_Mesh = mesh;
	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{

	}

	void GameObject::Draw(class ShaderProgram* shader)
	{
		m_Mesh->Draw();
	}
}