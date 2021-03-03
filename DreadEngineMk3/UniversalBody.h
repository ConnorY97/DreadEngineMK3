#pragma once
#include "Quad.h"
#include "Shader.h"
#include "Texture.h"
class UniversalBody
{
public:
	UniversalBody(glm::vec2 pos, glm::vec3 col, std::string texturePath);
	~UniversalBody(); 

	void Draw(Shader* shader); 
protected:
	Quad* m_body; 
	Texture* m_surface; 
};

