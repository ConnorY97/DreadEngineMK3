#pragma once
#include "glm.hpp"
#include <vector>
class Quad
{
public:
	Quad(glm::vec2 pos, glm::vec3 col);
	~Quad();

	void Bind(); 

	unsigned int GetVAO() { return VAO; }
protected:
	std::vector<float> m_verticies; 

	std::vector<unsigned int> m_indicies; 

	unsigned int VBO, VAO, EBO; 

	glm::vec2 m_pos; 

};

