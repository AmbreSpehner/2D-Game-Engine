#pragma once

#include <string>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "../gfx/structs/Size.h"

class TrueTypeFont
{
public:
	TrueTypeFont( ) = default;
	TrueTypeFont( const std::string& path, GLuint fontHeight = 32);
	TrueTypeFont( const std::string& path, GLui_Size& fontSize );

	// void RenderText( );

public:
	struct Character
	{
		GLuint TextureID;
	};

private:
	FT_Library ft;
	FT_Face face;

	
};