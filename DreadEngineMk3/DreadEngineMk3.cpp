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
	Quad* test = new Quad(glm::vec2(0.0, 0.0), glm::vec3(1, 0, 0)); 
	Quad* test1 = new Quad(glm::vec2(0.0f, 0.0f), glm::vec3(0, 1, 0)); 

	

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Game loop
	while (glfwWindowShouldClose(m_dreadEngine->GetCurrentContext()) == false)
	{
		m_dreadEngine->Update();
		glm::mat4 transform = glm::mat4(1.0f); 
		transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
		transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		m_simpleShader->use();
		unsigned int transformloc = glGetUniformLocation(m_simpleShader->ID, "transform"); 		
		glUniformMatrix4fv(transformloc, 1, GL_FALSE, glm::value_ptr(transform)); 
		test->Bind();
		transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(-0.5f, 0.5f, 0.0f));
		transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		//m_simpleShader->use();
		transformloc = glGetUniformLocation(m_simpleShader->ID, "transform");
		glUniformMatrix4fv(transformloc, 1, GL_FALSE, glm::value_ptr(transform));
		test1->Bind();
		//glBindVertexArray(VAO);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 
	}
	
	aie::Gizmos::destroy(); 

	delete m_dreadEngine;
	m_dreadEngine = nullptr;
	delete m_simpleShader;
	m_simpleShader = nullptr; 
	delete test;
	test = nullptr;
	delete test1; 
	test1 = nullptr;
	return 0;
}