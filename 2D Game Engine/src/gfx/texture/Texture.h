#pragma once

#include <string>

#include <GL/glew.h>
#include <glm/vec2.hpp>

#include "../structs/Size.h"

class Texture
{
public:
	Texture( const std::string& filepath );

	void Bind();
	void Unbind();

	const GLf_Size GetSize() const
	{
		return GLf_Size( static_cast<GLfloat>( width ), static_cast<GLfloat>( height ) );
	}

private:
	int width, height;

	GLuint textureID;
};