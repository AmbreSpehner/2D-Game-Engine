#include "TrueTypeFont.h"

#include <stdexcept>

TrueTypeFont::TrueTypeFont( const std::string path, GLuint fontHeight )
{
	if( FT_Init_FreeType( &ft ) )
	{
		throw std::runtime_error{ "FT_Init_FreeType failed!\n" };
	}

	if( FT_New_Face( ft, path.c_str( ), 0, &face ) )
	{
		throw std::runtime_error{ "FT_New_Face failed!\n" };
	}

	FT_Set_Pixel_Sizes( face, 0, fontHeight );

	glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

	for( GLubyte c = 0; c < 128; c++ )
	{
		if( FT_Load_Char( face, c, FT_LOAD_RENDER ) )
		{
			throw std::runtime_error{ "FT_Load_Char failed!" };
			continue;
		}

		GLuint textureID;
		glGenTextures( 1, &textureID );
		glBindTexture( GL_TEXTURE_2D, textureID );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 
					  0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer );

		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

		Character character = 
		{
			textureID,
			glm::ivec2( face->glyph->bitmap.width, face->glyph->bitmap.rows ),
			glm::ivec2( face->glyph->bitmap_left, face->glyph->bitmap_top ),
			face->glyph->advance.x
		};

		characterMap.insert( std::pair<GLchar, Character>( c, character ) );
	}

	glBindTexture( GL_TEXTURE_2D, 0 );

	FT_Done_Face( face );
	FT_Done_FreeType( ft );

	glGenVertexArrays( 1, &VAO );
	glGenBuffers( 1, &VBO );
	glBindVertexArray( VAO );
	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( GLfloat ) * 6 * 4, NULL, GL_DYNAMIC_DRAW );
	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof( GLfloat ), 0 );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
}

void TrueTypeFont::RenderText( Shader& shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, Colour& colour )
{
	shader.SetUniform1i( "useFont", true );
	shader.SetUniformVec4f( "fontColour", static_cast< glm::vec4 >( colour ) );

	glActiveTexture( GL_TEXTURE0 );
	glBindVertexArray( VAO );

	std::string::const_iterator it;
	for( it = text.begin( ); it != text.end( ); it++ )
	{
		Character ch = characterMap[*it];

		GLfloat xpos = x + ch.bearing.x * scale;
		GLfloat ypos = y - ( ch.size.y - ch.bearing.y ) * scale;

		GLfloat w = ch.size.x * scale;
		GLfloat h = ch.size.y * scale;

		GLfloat vertices[6][4] = {
			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos,     ypos,       0.0, 1.0 },
			{ xpos + w, ypos,       1.0, 1.0 },

			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos + w, ypos,       1.0, 1.0 },
			{ xpos + w, ypos + h,   1.0, 0.0 }
		};

		glBindTexture( GL_TEXTURE_2D, ch.textureID );

		glBindBuffer( GL_ARRAY_BUFFER, VBO );
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof( vertices ), vertices );
		glBindBuffer( GL_ARRAY_BUFFER, 0 );

		glDrawArrays( GL_TRIANGLES, 0, 6 );

		x += ( ch.advance >> 6 ) * scale;
	}

	glBindVertexArray( 0 );
	glBindTexture( GL_TEXTURE_2D, 0 );

	shader.SetUniform1i( "useFont", false );
}
