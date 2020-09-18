#pragma once



namespace fw
{
	class Mesh;
	class ShaderProgram;

class GameObject
{
public:
	GameObject(Mesh* mesh);
	~GameObject();

	void Update();
	void Draw(class ShaderProgram* shader);

	Mesh* m_Mesh = nullptr;
	ShaderProgram* m_Shader;
};

}


