#pragma once

#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "../gfx/structs/Size.h"

class TrueTypeFont
{
public:
	TrueTypeFont( ) = default;
	TrueTypeFont( const std::string& path, GLuint fontHeight = 32);
	TrueTypeFont( const std::string& path, GLui_Size& fontSize );

private:
	FT_Library m_FT;
	FT_Face m_Face;
};