#pragma once

#include <GL/glew.h>

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

	T x, y;
};

typedef Size<GLfloat> GLf_Size;
typedef Size<GLint> GLi_Size;
typedef Size<GLuint> GLui_Size;