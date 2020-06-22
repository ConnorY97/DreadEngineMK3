#include <iostream>
#include <crtdbg.h>
#include "Application.h"
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

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application* m_dreadEngine = new Application(SCREENWIDTH, SCREENHEIGHT, "DreadEngineMk3");
	Shader* m_simpleShader = new Shader("../Shaders/vert_shader.shader", "../Shaders/frag_shader.shader");
	Texture* m_squareSprite = new Texture("../Images/Square.png");
	Texture* m_ballSprite = new Texture("../Images/circle.png");

	std::vector<Quad*> m_squares;
	std::vector<Quad*> m_ballz; 



	for (size_t i = 0; i < QUADAMOUNT; i++)
	{
		Quad* temp = new Quad(glm::vec2(-0.5f + i * 0.25f, 0.60f), glm::vec3(0, 0, 0));
		m_squares.push_back(temp);
	}

	for (size_t i = 0; i < QUADAMOUNT; i++)
	{
		Quad* temp = new Quad(glm::vec2(-0.5f + i * 0.25f, 0.0f), glm::vec3(0, 0, 0)); 
		m_ballz.push_back(temp); 
	}

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Game loop
	while (glfwWindowShouldClose(m_dreadEngine->GetCurrentContext()) == false)
	{
		m_dreadEngine->Update(); 
		m_simpleShader->use(); 
		for (size_t i = 0; i < QUADAMOUNT; i++)
		{
			m_squares[i]->Draw(m_simpleShader, m_squareSprite);
		}

		for (size_t i = 0; i < QUADAMOUNT; i++)
		{
			m_ballz[i]->Draw(m_simpleShader, m_ballSprite);
		}
	}
	
	for (size_t i = 0; i < QUADAMOUNT; i++)
	{
		delete m_squares[i];
		m_squares[i] = nullptr;
	}

	for (size_t i = 0; i < QUADAMOUNT; i++)
	{
		delete m_ballz[i];
		m_ballz[i] = nullptr;
	}

	delete m_squareSprite;
	m_squareSprite = nullptr;
	delete m_ballSprite;
	m_ballSprite = nullptr;
	delete m_dreadEngine;
	m_dreadEngine = nullptr;
	delete m_simpleShader;
	m_simpleShader = nullptr; 
	return 0;
}