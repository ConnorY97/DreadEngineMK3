#pragma once
#include <iostream>
#include "Application.h"
#include "UniversalBody.h"
#include "Quad.h"
class Universe
{
public:
	Universe();
	~Universe(); 

	void Update(GLFWwindow* currentApp, Shader* shader); 


protected: 
	UniversalBody* m_sun; 

	std::vector<UniversalBody*> m_solarSystem;;
};

