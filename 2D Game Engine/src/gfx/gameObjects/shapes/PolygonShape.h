#pragma once

#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../buffers/VertexBuffer.h"
#include "../../buffers/IndexBuffer.h"
#include "../../buffers/VertexArray.h"

class PolygonShape
{
public:
	PolygonShape( ) = default;
	PolygonShape( std::vector<glm::vec3>& vertPos, glm::vec4& colour );
	PolygonShape( std::vector<glm::vec3>& vertPos, glm::vec4& colour, int type );

	void Render( );

private:
	glm::vec4 m_Colour;

	std::vector<glm::vec3> m_VertPos;

	GLuint m_VerticesCount;

	VertexBuffer m_VertVBO;
	VertexBuffer m_ColourVBO;

	VertexArray m_VAO;

private:
	enum ShaderLocation
	{
		POSITION = 0,
		COLOUR = 1,
		TEXTURE_COORD = 2
	};
};