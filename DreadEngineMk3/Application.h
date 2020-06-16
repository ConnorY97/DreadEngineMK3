#pragma once
#include "gl_core_4_5.h"
#include "glfw3.h"



class Application
{
public:
	Application(int width, int height, const char* name);

	~Application(); 

	GLFWwindow* GetCurrentContext() { return m_window;  }

protected:
	int Create(int width, int height, const char* name);

	GLFWwindow* m_window; 

};

