#include "UniversalBody.h"

UniversalBody::UniversalBody(glm::vec2 pos, glm::vec3 col)
{
	m_body = new Quad(pos, glm::vec3(col)); 
}

UniversalBody::~UniversalBody()
{
	delete m_body;
	m_body = nullptr; 
}

