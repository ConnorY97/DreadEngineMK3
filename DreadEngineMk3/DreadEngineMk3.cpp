#include <iostream>
#include <crtdbg.h>
#include "Application.h"
#include "Gizmos.h"
#include "glm.hpp"
#include "ext.hpp"
#include "Shader.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application* m_dreadEngine = new Application(1280, 780, "DreadEngineMk3");
	Shader* m_simpleShader = new Shader("../Shaders/vert_shader.shader", "../Shaders/frag_shader.shader"); 

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = 
	{
		//Positions				//Colours
		 0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	// top right
		 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	// bottom right
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	// bottom left
		-0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f   // top left 
	};
	unsigned int indices[] = 
	{  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	//Position attribute 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Colour attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Game loop
	while (glfwWindowShouldClose(m_dreadEngine->GetCurrentContext()) == false
			&& glfwGetKey(m_dreadEngine->GetCurrentContext(), GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		m_dreadEngine->Update(); 
		m_simpleShader->use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 
	}

	

	//aie::Gizmos::create(1000, 1000, 1000, 1000);
	//glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	//glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.0f);


	////Game Loop 
	//while (glfwWindowShouldClose(m_dreadEngine->GetCurrentContext()) == false
	//	&& glfwGetKey(m_dreadEngine->GetCurrentContext(), GLFW_KEY_ESCAPE) != GLFW_PRESS)
	//{
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	
	//	aie::Gizmos::clear(); 

	//	aie::Gizmos::addTransform(glm::mat4(1));

	//	glm::vec4 white(1);
	//	glm::vec4 black(0, 0, 0, 1);

	//	//for (int i = 0; i < 21; i++)
	//	//{
	//	//	aie::Gizmos::addLine(glm::vec3(-10 + i, 0, 10),
	//	//						glm::vec3(-10 + i, 0, -10),
	//	//						i == 10 ? white : black); 
	//	//	aie::Gizmos::addLine(glm::vec3(10, 0, -10 + i),
	//	//						glm::vec3(-10 + i, 0, 10),
	//	//						i == 10 ? white : black); 
	//	//}
	//	//aie::Gizmos::addLine(glm::vec3(0, 0, 0), glm::vec3(-10, 0, -10), white);
	//	//aie::Gizmos::addAABB(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), white);
	//	aie::Gizmos::draw(projection * view);


	//	glfwSwapBuffers(m_dreadEngine->GetCurrentContext());
	//	glfwPollEvents(); 
	//}
	
	aie::Gizmos::destroy(); 

	delete m_dreadEngine;
	m_dreadEngine = nullptr;
	delete m_simpleShader;
	m_simpleShader = nullptr; 

	return 0;
}