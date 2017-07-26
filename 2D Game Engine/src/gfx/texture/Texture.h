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
		return GLf_Size( ( GLfloat ) m_Width, ( GLfloat ) m_Height );
	}

private:
	int m_Width, m_Height;

	GLuint m_TextureID;
};