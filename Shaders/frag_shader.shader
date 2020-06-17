#version 330 core

out vec4 FragColour;

in vec4 vertColour; // the input variable from the vertex shader (same name and same type)  
in vec2 texCoord; 

uniform sampler2D ourTexture; 

void main()
{
    //FragColour = vertColour;
    FragColour = texture(ourTexture, texCoord);
}