#pragma once
#include "../Math/Vector.h"

namespace fw {

	class Vector2;
	class ShaderProgram;
	class Player;

	class Mesh
	{
	public:
		Mesh();
		Mesh(int primitiveType, int numVertices, const float* pVertices);
		virtual ~Mesh();

		void CreateShape(int primitiveType, int numVertices, const float* pVertices);
		void CreateCircle(int primitiveType, float radius, unsigned int numVertices, const float* pVertices);

		void SetUniform1f(ShaderProgram* pShader, char* name, float value);
		void SetUniform2f(ShaderProgram* pShader, char* name, Vector2 position);
		
		void SetPosition(Vector2 pos) { m_Position = pos; }

		void Draw(Vector2 position, ShaderProgram* pShader);

		Vector2 m_Position;


	protected:
		GLuint m_VBO = 0;

		int m_NumVertices = 0;
		int m_PrimitiveType = GL_POINTS;
		
		
	};

} // namespace fw