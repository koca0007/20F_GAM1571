#include "FrameworkPCH.h"

#include "Mesh.h"
#include "Utility/ShaderProgram.h"
#include "Utility/Helpers.h"
#include "Math/Vector.h"

#include "../../Framework/Libraries/imgui/imgui.h"

namespace fw {

	Mesh::Mesh()
	{
	}

	Mesh::Mesh(int primitiveType, int numVertices, const float* pVertices)
	{

	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &m_VBO);
	}

	void Mesh::CreateShape(int primitiveType, int numVertices, const float* pVertices)
	{
		// Generate a buffer for our vertex attributes.
		glGenBuffers(1, &m_VBO); // m_VBO is a GLuint.

		// Set this VBO to be the currently active one.
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

		m_NumVertices = numVertices;
		m_PrimitiveType = primitiveType;

		// Copy our attribute data into the VBO.
		int numAttributeComponents = m_NumVertices * 2; // x & y for each vertex.
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numAttributeComponents, pVertices, GL_STATIC_DRAW);
	}

	void Mesh::CreateCircle(int primitiveType, float radius, unsigned int numVertices, const float* pVertices)
	{
		float vertexCount = 0;
		if (m_VBO != 0)
			glDeleteBuffers(1, &m_VBO);

		glGenBuffers(1, &m_VBO);

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

		assert(radius > 0.0f);

		double pi = 3.14159265358979323846;
		double twoPi = pi * 2.0f;
		float theta = (twoPi / numVertices);
		float angle = 0;

		std::vector<Vector2> vertices;
		
		for (int i = 0; i < numVertices; i++)
		{
			Vector2 vertex;
			vertex.x = (radius * cosf(angle));
			vertex.y = (radius * sin(angle));

			vertices.push_back(vertex);
			vertexCount++;
			angle += theta;
		}

		m_NumVertices = vertexCount;
		int numAttributeComponents = vertexCount * 2;
		m_PrimitiveType = primitiveType;
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numAttributeComponents, &vertices[0], GL_STATIC_DRAW);
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

	void Mesh::Draw(Vector2 position, ShaderProgram* pShader)
	{
		glUseProgram(pShader->GetProgram());

		// Set this VBO to be the currently active one.
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

		// Get the attribute variable’s location from the shader.
		GLint loc = 0; //glGetAttribLocation( m_pShader->m_Program, "a_Position" );
		glEnableVertexAttribArray(loc);

		// Describe the attributes in the VBO to OpenGL.
		glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 8, (void*)0);

		/*Setup our uniforms.*/
		{
			/*SetUniform1f(pShader, "u_Time", (float)GetSystemTimeSinceGameStart());*/
			SetUniform2f(pShader, "u_Position", position);
		}

		// Draw the primitive.
		glDrawArrays(m_PrimitiveType, 0, m_NumVertices);
	}

} // namespace fw