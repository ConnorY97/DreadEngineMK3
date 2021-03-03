#include "Universe.h"
#include <iostream>



Universe::Universe()
{

}

Universe::~Universe()
{
}

void Universe::Update(GLFWwindow* currentApp)
{
	if (glfwGetKey(currentApp, GLFW_KEY_SPACE))
	{
		std::cout << "I am the universe" << std::endl; 
	}
}