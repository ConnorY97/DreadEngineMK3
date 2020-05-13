#include <iostream>
#include <crtdbg.h>
#include "Application.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application* m_dreadEngine = new Application(1280, 780, "DreadEngineMk3");

	//Game Loop 
	while (glfwWindowShouldClose(m_dreadEngine->GetCurrentContext()) == false
		&& glfwGetKey(m_dreadEngine->GetCurrentContext(), GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		//Game logic 

		glfwSwapBuffers(m_dreadEngine->GetCurrentContext());
		glfwPollEvents(); 
	}

	delete m_dreadEngine;
	m_dreadEngine = nullptr;

	return 0;
}