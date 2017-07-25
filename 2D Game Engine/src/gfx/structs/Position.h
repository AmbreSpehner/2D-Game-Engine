#pragma once

#include <glm/vec3.hpp>
#include <Box2D/Common/b2Math.h>

struct Position
{
	Position( ) = default;
	Position( float xIn, float yIn, float zIn = 0.0f )
	{
		x = xIn;
		y = yIn;
		z = zIn;
	}

	void Set( float xIn, float yIn, float zIn = 0.0f )
	{
		x = xIn;
		y = yIn;
		z = zIn;
	}

	const glm::vec3 ToVec3( ) const { return glm::vec3{ x, y, z }; }
	const b2Vec2 ToB2Vec2( ) const { return b2Vec2{ x, y }; }

	float x, y, z;
};