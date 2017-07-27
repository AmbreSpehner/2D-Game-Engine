#pragma once

struct Colour
{
	Colour( ) = default;
	Colour( const GLfloat r, const GLfloat g, const GLfloat b, const GLfloat a = 1.0f )
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	void Set( const GLfloat r, const GLfloat g, const GLfloat b, const GLfloat a = 1.0f )
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	GLfloat r, b, g, a;
};