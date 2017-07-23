/**
 *	@file	RectangleShape.cpp
 *	@author	BouwnLaw
 *	@date	09/07/2017
 *	@brief	Create a rectangular shape.
 *
 *	Create a rectangular shape with a given position, size and colour.
 */
#include "RectangleShape.h"

// Include Deps
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

RectangleShape::RectangleShape( const glm::vec3& position, const glm::vec2& size, const glm::vec4& colour )
	: Renderable( position, size, colour )
{
	std::vector<GLfloat> vertices =
	{
		0, 0, 0,					// Bottom left.
		0, m_Size.y, 0,				// Top left.
		m_Size.x, m_Size.y, 0,		// Top Right.	
		m_Size.x, 0, 0				// Bottom Right.
	};

	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,		// Bottom left.
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,		// Top left.
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,		// Top Right.	
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a		// Bottom Right.
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size(), 3 );
	m_ColourVBO = VertexBuffer( colours, colours.size(), 4 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );

	std::vector<GLuint> indices = { 0, 1, 2, 0, 2, 3 };
	m_IBO = IndexBuffer( indices, indices.size() );
}

RectangleShape::RectangleShape( const glm::vec3 & position, const glm::vec2 & size, const glm::vec4 & colour, int type )
	:
	Renderable( position, size, colour, type )
 {
	std::vector<GLfloat> vertices =
	{
		0, 0, 0,					// Bottom left.
		0, m_Size.y, 0,				// Top left.
		m_Size.x, m_Size.y, 0,		// Top Right.	
		m_Size.x, 0, 0				// Bottom Right.
	};

	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,		// Bottom left.
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,		// Top left.
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,		// Top Right.	
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a		// Bottom Right.
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_ColourVBO = VertexBuffer( colours, colours.size( ), 4 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );

	std::vector<GLuint> indices = { 0, 1, 2, 0, 2, 3 };
	m_IBO = IndexBuffer( indices, indices.size( ) );
 }

void RectangleShape::Render( Shader& shader )
{
	m_VAO.Bind();

	glm::mat4 model;
	model = glm::translate( model, m_Position );

	shader.SetUniformMat4f( "model", model );

	Renderable::RenderIndices();
}

void RectangleShape::SetPosition( const glm::vec3 & position )
{
	m_Position = position;
}

void RectangleShape::SetSize( const glm::vec2 & size )
{
	m_Size = size;

	std::vector<GLfloat> vertices =
	{
		0, 0, 0,			
		0, m_Size.y, 0,			
		m_Size.x, m_Size.y, 0,	
		m_Size.x, 0, 0			
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
}

void RectangleShape::SetColour( const glm::vec4 colour )
{
	m_Colour = colour;

	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a
	};

	m_ColourVBO = VertexBuffer( colours, colours.size( ), 4 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );
}
