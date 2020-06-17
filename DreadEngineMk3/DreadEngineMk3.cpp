#include <iostream>
#include <crtdbg.h>
#include "Application.h"
#include "Gizmos.h"
#include "glm.hpp"
#include "ext.hpp"
#include "Shader.h"
#include "Quad.h"
#include <vector>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application* m_dreadEngine = new Application(1280, 780, "DreadEngineMk3");
	Shader* m_simpleShader = new Shader("../Shaders/vert_shader.shader", "../Shaders/frag_shader.shader");

	std::vector<Quad*> m_quads; 

	for (size_t i = 0; i < 5; i++)
	{
		Quad* temp = new Quad(glm::vec2(i * 0.25f, 0.0f), glm::vec3(1, 0, 0));
		m_quads.push_back(temp); 
	}

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Game loop
	while (glfwWindowShouldClose(m_dreadEngine->GetCurrentContext()) == false)
	{
		m_dreadEngine->Update();
		for (size_t i = 0; i < 5; i++)
		{
			m_quads[i]->Draw(m_simpleShader); 
		}
	}
	
	for (size_t i = 0; i < 5; i++)
	{
		delete m_quads[i];
		m_quads[i] = nullptr;
	}
	aie::Gizmos::destroy(); 

	delete m_dreadEngine;
	m_dreadEngine = nullptr;
	delete m_simpleShader;
	m_simpleShader = nullptr; 
	return 0;
}