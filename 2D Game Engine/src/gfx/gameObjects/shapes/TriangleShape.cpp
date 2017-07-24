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

void TriangleShape::SetVertex( const glm::vec3 & vertex, int number )
{
	if( number == VertexNum::VERT_1 )
		m_VertPos1 = vertex;
	else if( number == VertexNum::VERT_2 )
		m_VertPos2 = vertex;
	else if( number == VertexNum::VERT_3 )
		m_VertPos3 = vertex;
	else
		std::cout << "Chosen vertex does not exist!\n";

	std::vector<GLfloat> vertices =
	{
		m_VertPos1.x, m_VertPos1.y, m_VertPos1.z,
		m_VertPos2.x, m_VertPos2.y, m_VertPos2.z,
		m_VertPos3.x, m_VertPos3.y, m_VertPos3.z
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
}

void TriangleShape::SetVertices( const glm::vec3 & vertPos1, const glm::vec3 & vertPos2, const glm::vec3 & vertPos3 )
{
	std::vector<GLfloat> vertices =
	{
		m_VertPos1.x, m_VertPos1.y, m_VertPos1.z,
		m_VertPos2.x, m_VertPos2.y, m_VertPos2.z,
		m_VertPos3.x, m_VertPos3.y, m_VertPos3.z
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
}

void TriangleShape::SetColour( const glm::vec4 & colour )
{
	m_Colour = colour;

	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a
	};

	m_ColourVBO = VertexBuffer( colours, colours.size( ), 4 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );
}

const glm::vec3 & TriangleShape::GetVertex( int number ) const
{
	if( number == VertexNum::VERT_1 )
		return m_VertPos1;
	else if( number == VertexNum::VERT_2 )
		return m_VertPos2;
	else if( number == VertexNum::VERT_3 )
		return m_VertPos3;
	else
		return m_VertPos1;
		std::cout << "Chosen vertex does not exist. The first vertex is returned in it's place\n";
}

const glm::vec4 & TriangleShape::GetColour( ) const
{
	return m_Colour;
}
