#include "Quad.h"
#include "gl_core_4_5.h"
#include "ext.hpp"

Quad::Quad(glm::vec2 pos, glm::vec3 col)
{
	m_vertices =
	{
		//Position								//Colour
		0.1f,	0.1f,	0.0f,	col.r, col.g, col.b,
		0.1f,	-0.1f,	0.0f,	col.r, col.g, col.b,
		-0.1f,	-0.1f,	0.0f,	col.r, col.g, col.b,
		-0.1f,	0.1f,	0.0f,	col.r, col.g, col.b
	};
	
	m_indices =
	{
		0, 1, 3,
		1, 2, 3
	};

	m_pos = glm::vec4(pos, 0.0, 1.0); 
	m_transform = glm::mat4(1.0f); 
	m_transform[3] = m_pos; 
	 

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 24, m_vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, m_indices.data(), GL_STATIC_DRAW);

	//Position attribute 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Colour attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray any ways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

Quad::~Quad()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); 
	glBindVertexArray(0);
}

void Quad::Draw(Shader* shader)
{
	shader->use();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	unsigned int transformLoc = glGetUniformLocation(shader->ID, "transform"); 
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(m_transform));
}

void Quad::Position(glm::vec2 pos)
{
	m_pos = glm::vec4(pos, 0.0, 1.0);
	m_transform = glm::mat4(1.0f);
	m_transform[3] = m_pos;
}
