/**
 *	@file	Texture.cpp
 *	@author	BouwnLaw
 *	@date	09/07/2017
 *	@brief	Loads a texture.
 *
 *	Loads a texture from a file.
 */
#include "Texture.h"

// Include STL
#include <iostream>

// Include Deps
#include <SOIL/SOIL.h>

Texture::Texture( const std::string& filepath )
{
	glGenTextures( 1, &m_TextureID );

	Bind();

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

	auto data = SOIL_load_image( filepath.c_str(), &m_Width, &m_Height, 0, SOIL_LOAD_RGBA );

	if( data )
	{
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
		glGenerateMipmap( GL_TEXTURE_2D );
	}
	else
	{
		std::cout << "Failed to load texture.\n";
	}


	SOIL_free_image_data( data );

	Unbind();
}

void Texture::Bind()
{
	glBindTexture( GL_TEXTURE_2D, m_TextureID );
}

void Texture::Unbind()
{
	glBindTexture( GL_TEXTURE_2D, 0 );
}