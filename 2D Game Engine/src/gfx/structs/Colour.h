#pragma once

struct Colour
{
	Colour( ) = default;
	Colour( GLfloat rIn, GLfloat gIn, GLfloat bIn, GLfloat aIn = 1.0f )
	{
		r = rIn;
		g = gIn;
		b = bIn;
		a = aIn;
	}

	void Set( GLfloat rIn, GLfloat gIn, GLfloat bIn, GLfloat aIn = 1.0f )
	{
		r = rIn;
		g = gIn;
		b = bIn;
		a = aIn;
	}

	GLfloat r, b, g, a;
};