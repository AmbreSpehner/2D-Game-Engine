#include "Texture.h"

#include <stdexcept>

#include <SOIL/SOIL.h>

#include <iostream>

Texture::Texture( const std::string& filepath )
{
	glGenTextures( 1, &textureID );

	Bind();

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

	auto file = filepath.c_str( );
	auto data = SOIL_load_image( file, &width, &height, 0, SOIL_LOAD_RGBA );

	if( data )
	{
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
		glGenerateMipmap( GL_TEXTURE_2D );
	}
	else
		std::cout << SOIL_last_result( ) << '\n';
		// throw std::runtime_error{ "Failed to load texture:" };

	SOIL_free_image_data( data );

	Unbind();
}

Texture::Texture( std::vector<Pixel>& buffer, GLfloat width, GLfloat height )
{
	glGenTextures( 1, &textureID );
	glBindTexture( GL_TEXTURE_2D, textureID );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	if( !buffer.empty( ) )
	{
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height,
					  0, GL_RGBA, GL_UNSIGNED_BYTE, &buffer.front( ) );
	}

	glBindTexture( GL_TEXTURE_2D, 0 );
}

void Texture::Bind()
{
	glBindTexture( GL_TEXTURE_2D, textureID );
}

void Texture::Unbind()
{
	glBindTexture( GL_TEXTURE_2D, 0 );
}