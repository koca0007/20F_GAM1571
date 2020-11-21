#pragma once
#include "../Math/Vector.h"

namespace fw {


	class Vector2;
	class ShaderProgram;
	class Player;
	class Texture;

	struct VertexFormat
	{
		float x;
		float y;
		float u;
		float v;

		VertexFormat(float nx, float ny, float nu, float nv)
		{
			x = nx;
			y = ny;
			u = nu;
			v = nv;
		}
	};

	class Mesh
	{
	public:
		Mesh();
		Mesh(int primitiveType, int numVertices, const VertexFormat* pVertices);
		virtual ~Mesh();

		void CreateShape(int primitiveType, int numVertices, const VertexFormat* pVertices);
		void CreateCircle(int primitiveType, float radius, unsigned int numVertices);

		void SetUniform1f(ShaderProgram* pShader, char* name, float value);
		void SetUniform2f(ShaderProgram* pShader, char* name, Vector2 position);
		void SetUniform4f(ShaderProgram* pShader, char* name, Vector4 color);
		void SetUniform1i(ShaderProgram* pShader, char* name, int value);

		void Draw(Vector2 position, ShaderProgram* pShader, Texture* pTexture, Vector4 color, Vector2 UVScale, Vector2 UVOffset);

	protected:
		GLuint m_VBO = 0;

		int m_NumVertices = 0;
		int m_PrimitiveType = GL_POINTS;
	};

} // namespace fw