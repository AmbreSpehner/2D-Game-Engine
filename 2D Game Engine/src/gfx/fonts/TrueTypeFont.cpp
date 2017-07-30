#include "TrueTypeFont.h"

#include <stdexcept>

#include "../texture/TextureCodex.h"

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

	for( GLchar c = 0; c < 128; c++ )
	{
		std::vector<Texture::Pixel> buffer;

		if( FT_Load_Char( face, c, FT_LOAD_RENDER ) )
		{
			throw std::runtime_error{ "FT_Load_Char failed!" };
			continue;
		}

		int totalPixels = face->glyph->bitmap.width * face->glyph->bitmap.rows;

		for( int i = 0; i < totalPixels; i++ )
		{
			Texture::Pixel pixel;
			pixel.r = 255;
			pixel.g = 255;
			pixel.b = 255;
			pixel.a = face->glyph->bitmap.buffer[i];

			buffer.emplace_back( pixel );
		}

		Character character =
		{
			TextureCodex::Acquire( c, buffer, face->glyph->bitmap.width, face->glyph->bitmap.rows ),
			glm::ivec2( face->glyph->bitmap.width, face->glyph->bitmap.rows ),
			glm::ivec2( face->glyph->bitmap_left, face->glyph->bitmap_top ),
			face->glyph->advance.x
		};

		characterMap.insert( std::pair<GLchar, Character>( c, character ) );
	}

	FT_Done_Face( face );
	FT_Done_FreeType( ft );
}

void TrueTypeFont::RenderText( Shader& shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, Colour& colour )
{
	std::string::const_iterator it;
	for( it = text.begin( ); it != text.end( ); it++ )
	{
		Character ch = characterMap[*it];

		GLfloat xPos = x + ch.bearing.x * scale;
		GLfloat yPos = y - ( ch.size.y - ch.bearing.y ) * scale;

		GLfloat w = ch.size.x * scale;
		GLfloat h = ch.size.y * scale;

		RenderableImage image( Position( xPos, yPos, 0.0f ), GLf_Size( w, h ), colour, ch.pTexture );

		x += ( ch.advance >> 6 ) * scale;
	}
}
