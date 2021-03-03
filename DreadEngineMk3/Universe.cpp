#include "Universe.h"
#include <iostream>



Universe::Universe()
{
	m_sun = new UniversalBody(glm::vec2(0, 0), glm::vec3(1, 1, 0)); 
}

Universe::~Universe()
{
	delete m_sun;
	m_sun = nullptr; 
}

void Universe::Update(GLFWwindow* currentApp)
{
	if (glfwGetKey(currentApp, GLFW_KEY_SPACE))
	{
		std::cout << "I am the universe" << std::endl; 
	}
}