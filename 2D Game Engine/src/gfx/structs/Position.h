#pragma once

#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <Box2D/Common/b2Math.h>

template<typename T>
struct Position
{
	Position( ) = default;
	Position( const T x, const T y, const T z = 0.0f )
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Set( const T x, const T y, const T z = 0.0f )
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	explicit operator glm::vec3( ) const { return glm::vec3{ x, y, z }; }
	explicit operator glm::vec2( ) const { return glm::vec2{ x, y }; }
	explicit operator b2Vec2( ) const { return b2Vec2{ x, y }; }

	T x, y, z;
};

typedef Size<GLfloat> GLf_Pos;
typedef Size<GLint> GLi_Pos;
typedef Size<GLuint> GLui_Pos;