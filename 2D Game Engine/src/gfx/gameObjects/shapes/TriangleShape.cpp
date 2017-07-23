#include "TriangleShape.h"

#include <vector>

#include <iostream>

TriangleShape::TriangleShape( const glm::vec3 & vertPos1, const glm::vec3 & vertPos2, const glm::vec3 & vertPos3, const glm::vec4& colour )
	:
	Renderable( vertPos1, vertPos2, vertPos3, colour )
{
	std::vector<GLfloat> vertices =
	{
		m_VertPos1.x, m_VertPos1.y, m_VertPos1.z,
		m_VertPos2.x, m_VertPos2.y, m_VertPos2.z,
		m_VertPos3.x, m_VertPos3.y, m_VertPos3.z
	};

	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_ColourVBO = VertexBuffer( colours, colours.size( ), 4 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );

	m_VerticesCount = vertices.size( ) / m_VertVBO.GetComponentCount( );
}

TriangleShape::TriangleShape( const glm::vec3 & vertPos1, const glm::vec3 & vertPos2, const glm::vec3 & vertPos3, const glm::vec4 & colour, int type )
	:
	Renderable( vertPos1, vertPos2, vertPos3, colour, type )
{
	std::vector<GLfloat> vertices =
	{
		m_VertPos1.x, m_VertPos1.y, m_VertPos1.z,
		m_VertPos2.x, m_VertPos2.y, m_VertPos2.z,
		m_VertPos3.x, m_VertPos3.y, m_VertPos3.z
	};

	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_ColourVBO = VertexBuffer( colours, colours.size( ), 4 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );

	m_VerticesCount = vertices.size( ) / m_VertVBO.GetComponentCount( );
}

void TriangleShape::Render( Shader& shader )
{
	m_VAO.Bind( );

	Renderable::RenderVertices( );
}