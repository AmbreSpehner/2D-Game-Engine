#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../buffers/VertexBuffer.h"
#include "../buffers/VertexArray.h"

class TriangleShape
{
public:
	TriangleShape( ) = default;
	TriangleShape( const glm::vec3& vertPos1, const glm::vec3& vertPos2, const glm::vec3& vertPos3, const glm::vec4& colour );

	void Render( );

private:
	glm::vec3 m_VertPos1;
	glm::vec3 m_VertPos2;
	glm::vec3 m_VertPos3;
	glm::vec4 m_Colour;

	VertexBuffer m_VertVBO;
	VertexBuffer m_ColourVBO;
	VertexArray m_VAO;

private:
	/**
	*	@brief	Enum for uniform location.
	*
	*	Enum to store the uniform location within the shader.
	*/
	enum ShaderLocation
	{
		POSITION = 0,
		COLOUR = 1,
		TEXTURE_COORD = 2
	};
};