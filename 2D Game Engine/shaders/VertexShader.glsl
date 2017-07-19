#version 330 core

layout( location = 0 ) in vec3 position;
layout( location = 1 ) in vec4 colour;
layout( location = 2 ) in vec2 texCoord;

out vec4 myColour;
out vec2 myTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4( position, 1.0 );
	myColour = colour;
	myTexCoord = texCoord;
}