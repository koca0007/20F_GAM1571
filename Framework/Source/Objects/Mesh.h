#pragma once

namespace fw {
	
	class ShaderProgram;

	class Mesh 
	{
	public:
		Mesh(ShaderProgram* shader);
		virtual ~Mesh();

		void Draw();

		void MakeHumanoid();
		void MakeAnimal();

	protected:
		GLuint m_VBO = 0;
		ShaderProgram* m_Shader;
		int m_NumVertices = 0;
		int m_PrimitiveType = GL_POINTS;
	};

} // namespace fw