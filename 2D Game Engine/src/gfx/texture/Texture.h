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

	const Size GetSize() const
	{
		return Size( ( float ) m_Width, ( float ) m_Height );
	}

private:
	int m_Width, m_Height;

	GLuint m_TextureID;
};