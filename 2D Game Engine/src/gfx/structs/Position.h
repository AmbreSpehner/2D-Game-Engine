#pragma once

#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <Box2D/Common/b2Math.h>

struct Position
{
	Position( ) = default;
	Position( GLfloat xIn, GLfloat yIn, GLfloat zIn = 0.0f )
	{
		x = xIn;
		y = yIn;
		z = zIn;
	}

	void Set( GLfloat xIn, GLfloat yIn, GLfloat zIn = 0.0f )
	{
		x = xIn;
		y = yIn;
		z = zIn;
	}

	explicit operator glm::vec3( ) const { return glm::vec3{ x, y, z }; }
	explicit operator glm::vec2( ) const { return glm::vec2{ x, y }; }
	explicit operator b2Vec2( ) const { return b2Vec2{ x, y }; }

	GLfloat x, y, z;
};