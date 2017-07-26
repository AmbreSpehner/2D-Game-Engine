#include "TrueTypeFont.h"

#include <stdexcept>

TrueTypeFont::TrueTypeFont( const std::string& path, GLuint fontHeight = 32 )
{
	if( FT_Init_FreeType( &m_FT ) )
	{
		throw std::runtime_error{ "FT_Init_FreeType failed!\n" };
	}

	if( FT_New_Face( m_FT, path.c_str( ), 0, &m_Face ) )
	{
		throw std::runtime_error{ "FT_New_Face failed!\n" };
	}

	FT_Set_Pixel_Sizes( m_Face, 0, fontHeight );
}

TrueTypeFont::TrueTypeFont( const std::string& path, GLui_Size& fontSize = { 0, 32 } )
{
	if( FT_Init_FreeType( &m_FT ) )
	{
		throw std::runtime_error{ "FT_Init_FreeType failed!\n" };
	}

	if( FT_New_Face( m_FT, path.c_str( ), 0, &m_Face ) )
	{
		throw std::runtime_error{ "FT_New_Face failed!\n" }; 
	}

	FT_Set_Pixel_Sizes( m_Face, fontSize.x, fontSize.y );
}
