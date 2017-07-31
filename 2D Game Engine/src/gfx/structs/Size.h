#pragma once

#include <GL/glew.h>
#include <glm/mat2x2.hpp>
#include <Box2D/Common/b2Math.h>

template<typename T>
struct Size
{
	Size( ) = default;
	Size( const T x, const T y )
	{
		this->x = x;
		this->y = y;
	}

	void Set( const T x, const T y )
	{
		this->x = x;
		this->y = y;
	}
	
	explicit operator glm::vec2( ) const { return glm::vec2( x, y ); }
	explicit operator b2Vec2( ) const { return b2Vec2( x, y ); }

	T x, y;
};

typedef Size<GLfloat> GLf_Size;
typedef Size<GLint> GLi_Size;
typedef Size<GLuint> GLui_Size;