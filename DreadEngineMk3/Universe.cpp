#include "Universe.h"

Universe::Universe()
{

	m_sun = new UniversalBody(glm::vec2(0, 0), glm::vec3(1, 1, 0), "../Images/circle.png");

	m_solarSystem.push_back(m_sun); 
}

Universe::~Universe()
{
	delete m_sun;
	m_sun = nullptr; 
}

void Universe::Update(GLFWwindow* currentApp, Shader* shader)
{
	for (int i = 0; i < m_solarSystem.size(); i++)
	{
		m_solarSystem[i]->Draw(shader); 
	}

	if (glfwGetKey(currentApp, GLFW_KEY_SPACE))
	{
		std::cout << "I am the universe" << std::endl; 
	}
}