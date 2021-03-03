#pragma once
#include "Application.h"
#include "UniversalBody.h"
class Universe
{
public:
	Universe();
	~Universe(); 

	void Update(GLFWwindow* currentApp); 


protected: 
	UniversalBody* m_sun; 
};

