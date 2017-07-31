#pragma once

#include <GL/glew.h>
#include <glm/vec4.hpp>

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

	explicit operator glm::vec4( ) const { return glm::vec4( r, g, b, a ); }

	GLfloat r, b, g, a;
};