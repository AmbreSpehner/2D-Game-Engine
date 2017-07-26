#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

class TrueTypeFont
{
public:
	TrueTypeFont( ) = default;
	TrueTypeFont( );

private:
	FT_Library m_FT;
};