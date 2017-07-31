#pragma once

#include <glm/vec4.hpp>

template<typename T>
struct Colour
{
	Colour( ) = default;
	Colour( const T r, const T g, const T b, const T a = 1.0f )
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	void Set( const T r, const T g, const T b, const T a = 1.0f )
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	explicit operator glm::vec4( ) const { return glm::vec4( r, g, b, a ); }

	T r, b, g, a;
};

typedef Size<GLfloat> GLf_Colour;
typedef Size<GLint> GLi_Colour;
typedef Size<GLuint> GLui_Colour;