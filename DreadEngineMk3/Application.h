#pragma once
#include "gl_core_4_5.h"
#include "glfw3.h"



class Application
{
public:
	Application(int width, int height, const char* name);


	~Application(); 

	void Update(); 

	GLFWwindow* GetCurrentContext() { return m_window;  }

protected:
	int Create(int width, int height, const char* name);

	GLFWwindow* m_window; 

	//Delta time 
	double m_last = 0.0; 
	double m_now = 0.0; 
	float m_delaTime = 1.0f; 

};

