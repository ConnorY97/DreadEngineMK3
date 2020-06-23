#version 330 core

out vec4 FragColour;

in vec4 vertColour; // the input variable from the vertex shader (same name and same type)  
in vec2 texCoord; 

uniform sampler2D ourTexture; 

void main()
{
    vec4 texColour = texture(ourTexture, texCoord) * vertColour; 
    //FragColour = vertColour;
    if (texColour.a < 0.1)
        discard; 
 
    FragColour = texColour;// *vec4(vertColour, 1.0);
}