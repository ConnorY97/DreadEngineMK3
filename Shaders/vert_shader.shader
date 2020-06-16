#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aCol; 

out vec4 vertColour;
uniform  mat4 transform; 


void main()
{
    gl_Position = transform * vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertColour = vec4(aCol, 1.0); //Colour  vec4(0.5, 0.0, 0.0, 1.0); // using the colour assigned to it 
}