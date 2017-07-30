#pragma once

#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/vec2.hpp>

#include "../structs/Size.h"

class Texture
{
public:
	struct Pixel
	{
		std::uint8_t r, g, b, a;
	};

public:
	Texture( ) = default;
	Texture( const std::string& filepath );
	Texture( std::vector<Pixel>& buffer, GLfloat width, GLfloat height );

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