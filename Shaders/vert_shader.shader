#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aCol; 

out vec4 vertColour;


void main()
{
    gl_Position = vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertColour = vec4(0.5, 0.0, 0.0, 1.0); // using the colour assinged to it 
}