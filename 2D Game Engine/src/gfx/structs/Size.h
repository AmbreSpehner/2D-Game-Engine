#pragma once

#include <GL/glew.h>

template<typename T>
struct Size
{
	Size( ) = default;
	Size( T xIn, T yIn )
	{
		x = xIn;
		y = yIn;
	}

	void Set( T xIn, T yIn )
	{
		x = xIn;
		y = yIn;
	}

	T x, y;
};

typedef Size<GLfloat> GLf_Size;
typedef Size<GLint> GLi_Size;
typedef Size<GLuint> GLui_Size;