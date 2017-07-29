#pragma once

#include <string>
#include <map>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "../gfx/buffers/VertexBuffer.h"
#include "../gfx/buffers/VertexArray.h"
#include "../shader/Shader.h"
#include "../gfx/structs/Structs.h"

class TrueTypeFont
{
public:
	TrueTypeFont( ) = default;
	TrueTypeFont( const std::string path, GLuint fontHeight = 32);

	void RenderText( Shader& shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, Colour& colour );

public:
	struct Character
	{
		GLuint textureID;
		glm::ivec2 size;
		glm::ivec2 bearing;
		GLuint advance;
	};

	struct Pixel
	{
		std::uint8_t r, g, b, a;
	};

private:
	FT_Library ft;
	FT_Face face;

	std::map<GLchar, Character> characterMap;
	std::vector<Pixel> buffer;

	GLuint VAO, VBO;
};