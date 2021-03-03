#include <iostream>
#include <crtdbg.h>
#include "Application.h"
#include "Universe.h"
#include "Gizmos.h"
#include "glm.hpp"
#include "ext.hpp"
#include "Shader.h"
#include "Quad.h"
#include <vector>
#include "Texture.h"


#define QUADAMOUNT 5

#define SCREENWIDTH 512
#define SCREENHEIGHT 640

void CreateBall(std::vector<Quad*>& list);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application* m_dreadEngine = new Application(SCREENWIDTH, SCREENHEIGHT, "DreadEngineMk3");
	Shader* m_simpleShader = new Shader("../Shaders/vert_shader.shader", "../Shaders/frag_shader.shader");

	Universe* m_universe = new Universe(); 
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Game loop
	while (glfwWindowShouldClose(m_dreadEngine->GetCurrentContext()) == false)
	{
		m_dreadEngine->Update(); 
		m_simpleShader->use(); 
		m_universe->Update(m_dreadEngine->GetCurrentContext(), m_simpleShader); 
	}
	

	delete m_dreadEngine;
	m_dreadEngine = nullptr;
	delete m_simpleShader;
	m_simpleShader = nullptr; 
	delete m_universe; 
	m_universe = nullptr; 
	return 0;
}

void CreateBall(std::vector<Quad*>& list)
{
	Quad* temp = new Quad(glm::vec2(0.0f, 0.0f), glm::vec3(0, 0, 0));
	list.push_back(temp); 
}