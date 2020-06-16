#version 330 core

out vec4 FragColour;

in vec4 vertColour; // the input variable from the vertex shader (same name and same type)  

void main()
{
    FragColour = vertColour;
}