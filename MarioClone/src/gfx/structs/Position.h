#pragma once

#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <Box2D/Common/b2Math.h>

struct Position
{
	Position( ) = default;
	Position( const GLfloat x, const GLfloat y, const GLfloat z = 0.0f )
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Set( const GLfloat x, const GLfloat y, const GLfloat z = 0.0f )
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	explicit operator glm::vec3( ) const { return glm::vec3{ x, y, z }; }

	GLfloat x, y, z;
};