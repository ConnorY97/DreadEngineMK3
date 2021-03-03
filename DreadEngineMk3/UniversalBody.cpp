#include "UniversalBody.h"

UniversalBody::UniversalBody(glm::vec2 pos, glm::vec3 col, std::string texturePath)
{
	m_body = new Quad(pos, glm::vec3(col)); 
	m_surface = new Texture(texturePath);
}

UniversalBody::~UniversalBody()
{
	delete m_body;
	m_body = nullptr; 
}

void UniversalBody::Draw(Shader* shader)
{
	m_body->Draw(shader, m_surface); 
}

