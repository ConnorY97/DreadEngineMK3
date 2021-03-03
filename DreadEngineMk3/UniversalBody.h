#pragma once
#include "Quad.h"
class UniversalBody
{
public:
	UniversalBody(glm::vec2 pos, glm::vec3 col);
	~UniversalBody(); 
protected:
	Quad* m_body; 
};

