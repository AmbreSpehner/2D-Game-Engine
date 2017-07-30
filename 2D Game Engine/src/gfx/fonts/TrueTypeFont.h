#pragma once

#include <string>
#include <map>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "../gameObjects/RenderableImage.h"

class TrueTypeFont
{
public:
	TrueTypeFont( ) = default;
	TrueTypeFont( const std::string path, GLuint fontHeight = 32);

	void RenderText( Shader& shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, Colour& colour );

public:
	struct Character
	{
		std::shared_ptr<Texture> pTexture;
		glm::ivec2 size;
		glm::ivec2 bearing;
		GLuint advance;
	};

private:
	FT_Library ft;
	FT_Face face;

	std::map<GLchar, Character> characterMap;
};