#include "FrameworkPCH.h"

#include "Mesh.h"
#include "Utility/ShaderProgram.h"
#include "Utility/Helpers.h"
#include "Math/Vector.h"

#include "../../Framework/Libraries/imgui/imgui.h"
#include "Texture.h"

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062

namespace fw {

	Mesh::Mesh()
	{
	}

	Mesh::Mesh(int primitiveType, int numVertices, const VertexFormat* pVertices)
	{
		CreateShape(primitiveType,  numVertices, pVertices);
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &m_VBO);
	}

	void Mesh::CreateShape(int primitiveType, int numVertices, const VertexFormat* pVertices)
	{
		glDeleteBuffers(1, &m_VBO);

		// Generate a buffer for our vertex attributes.
		glGenBuffers(1, &m_VBO); // m_VBO is a GLuint.

		// Set this VBO to be the currently active one.
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

		m_NumVertices = numVertices;
		m_PrimitiveType = primitiveType;

		glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * m_NumVertices, pVertices, GL_STATIC_DRAW);

	}

	void Mesh::CreateCircle(int primitiveType, float radius, unsigned int numVertices)
	{	
		assert(radius > 0.0f);
		std::vector<VertexFormat> vertices;

		float segmentRadians = 2 * PI / numVertices;

		for (unsigned int i = 0; i <= numVertices; i++)
		{
			float angle = segmentRadians * i;

			float x = cosf(angle) * radius;
			float y = sinf(angle) * radius;

			vertices.push_back(VertexFormat(x, y, 0, 0));
		}

		CreateShape(primitiveType, numVertices, &vertices[0]);
	}

	void Mesh::SetUniform1f(ShaderProgram* pShader, char* name, float value)
	{
		int loc = glGetUniformLocation(pShader->GetProgram(), name);
		glUniform1f(loc, value);
	}

	void Mesh::SetUniform2f(ShaderProgram* pShader, char* name, Vector2 position)
	{
		int pos = glGetUniformLocation(pShader->GetProgram(), name);
		glUniform2f(pos, position.x, position.y );
	}

	void Mesh::SetUniform4f(ShaderProgram* pShader, char* name, Vector4 value)
	{
		int loc = glGetUniformLocation(pShader->GetProgram(), name);
		glUniform4f(loc, value.x, value.y, value.z, value.w);
	}

	void Mesh::SetUniform1i(ShaderProgram* pShader, char* name, int value)
	{
		int loc = glGetUniformLocation(pShader->GetProgram(), name);
		glUniform1i(loc, value);
	}

	void Mesh::Draw(Vector2 position, ShaderProgram* pShader, Texture* pTexture, Vector4 color)
	{
		glUseProgram(pShader->GetProgram());

		// Set this VBO to be the currently active one.
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

		// Get the attribute variable’s location from the shader.
		GLint loc = glGetAttribLocation( pShader->GetProgram(), "a_Position" );
		if (loc != -1)
		{
			glEnableVertexAttribArray(loc);
			glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 16, (void*)0);
		}

		loc = glGetAttribLocation(pShader->GetProgram(), "a_UVCoord");
		if (loc != -1)
		{
			glEnableVertexAttribArray(loc);
			glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 16, (void*)8);
		}

		/*Setup the uniforms.*/
		{
			SetUniform4f(pShader, "u_Color", color);
			SetUniform2f(pShader, "u_Position", position);

			if (pTexture != nullptr)
			{
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, pTexture->GetHandle());
				SetUniform1i(pShader, "u_Texture", 0);
			}	
		}

		// Draw the primitive.
		glDrawArrays(m_PrimitiveType, 0, m_NumVertices);
	}

} // namespace fw