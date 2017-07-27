#include "TrueTypeFont.h"

#include <stdexcept>

TrueTypeFont::TrueTypeFont( const std::string& path, GLuint fontHeight )
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

	
}

TrueTypeFont::TrueTypeFont( const std::string& path, GLui_Size& fontSize )
{
	if( FT_Init_FreeType( &ft ) )
	{
		throw std::runtime_error{ "FT_Init_FreeType failed!\n" };
	}

	if( FT_New_Face( ft, path.c_str( ), 0, &face ) )
	{
		throw std::runtime_error{ "FT_New_Face failed!\n" }; 
	}

	FT_Set_Pixel_Sizes( face, fontSize.x, fontSize.y );
}
