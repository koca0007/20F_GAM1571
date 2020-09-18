#include "FrameworkPCH.h"
#include "Mesh.h"
#include "GameObject.h"
#include "Utility/ShaderProgram.h"



namespace fw
{
	GameObject::GameObject(Mesh* mesh)
	{
		m_Mesh = mesh;
	}

	GameObject::~GameObject()
	{
		if (m_Mesh != nullptr)
		{
			delete m_Mesh;
		}
		if (m_Shader != nullptr)
		{
			delete m_Shader;
		}
	}

	void GameObject::Update()
	{

	}

	void GameObject::Draw(class ShaderProgram* shader)
	{
		m_Mesh->Draw();
	}
}