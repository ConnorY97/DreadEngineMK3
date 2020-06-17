#pragma once
#include "glm.hpp"
#include <vector>
#include "Shader.h"
class Quad
{
public:
	Quad(glm::vec2 pos, glm::vec3 col);
	~Quad();

	void Draw(Shader* shader);

	void Position(glm::vec2 pos); 

	unsigned int GetVAO() { return VAO; }
protected:
	std::vector<float> m_vertices; 

	std::vector<unsigned int> m_indices; 

	unsigned int VBO, VAO, EBO; 

	glm::vec4 m_pos;

	glm::mat4 m_transform;

};

