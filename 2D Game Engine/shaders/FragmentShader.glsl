#version 330 core

out vec4 colour;

in vec4 myColour;
in vec2 myTexCoord;

uniform bool useTexture;
uniform sampler2D colourTexture;

void main()
{
	if( useTexture )
	{
		colour = texture2D( colourTexture, myTexCoord );
	}
	else
	{
		colour = myColour;
	}
}