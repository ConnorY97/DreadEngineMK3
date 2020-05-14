#include <iostream>
#include <crtdbg.h>
#include "Application.h"
#include "Gizmos.h"
#include "glm.hpp"
#include "ext.hpp"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application* m_dreadEngine = new Application(1280, 780, "DreadEngineMk3");

	aie::Gizmos::create(100, 100, 100, 100); 
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.0f); 

	//Game Loop 
	while (glfwWindowShouldClose(m_dreadEngine->GetCurrentContext()) == false
		&& glfwGetKey(m_dreadEngine->GetCurrentContext(), GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		aie::Gizmos::clear(); 

		aie::Gizmos::addTransform(glm::mat4(1));

		glm::vec4 white(1);
		glm::vec4 black(0, 0, 0, 1);

		/*for (int i = 0; i < 21; i++)
		{
			aie::Gizmos::addLine(glm::vec3(-10 + i, 0, 10),
								glm::vec3(-10 + i, 0, -10),
								i == 10 ? white : black); 
			aie::Gizmos::addLine(glm::vec3(10, 0, -10 + i),
								glm::vec3(-10 + i, 0, 10),
								i == 10 ? white : black); 
		}*/
		//aie::Gizmos::addLine(glm::vec3(0, 0, 0), glm::vec3(-10, 0, -10), white); 
		aie::Gizmos::addAABB(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), white); 
		aie::Gizmos::draw(projection * view);


		glfwSwapBuffers(m_dreadEngine->GetCurrentContext());
		glfwPollEvents(); 
	}
	
	aie::Gizmos::destroy(); 

	delete m_dreadEngine;
	m_dreadEngine = nullptr;

	return 0;
}