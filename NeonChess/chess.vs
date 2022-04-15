#version 330 core
layout (location = 0) in vec3 aPos;
layout (lcoation = 1) in vec3 pieceColour;

out vec3 ourColor;

uniform mat4 MVP;


void main()
{

	gl_Position = vec4(aPos, 1.0);
	
	ourColor = pieceColour;

}