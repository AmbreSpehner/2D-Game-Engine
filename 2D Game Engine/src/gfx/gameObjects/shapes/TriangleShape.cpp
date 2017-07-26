#include "TriangleShape.h"

#include <vector>

#include <stdexcept>

TriangleShape::TriangleShape( const Position& p1, const Position& p2, const Position& p3, const Colour& colour )
	:
	Renderable( p1, p2, p3, colour )
{
	std::vector<GLfloat> vertices =
	{
		m_P1.x, m_P1.y, m_P1.z,
		m_P2.x, m_P2.y, m_P2.z,
		m_P3.x, m_P3.y, m_P3.z
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

void TriangleShape::SetVertex( const Position& vertex, int number )
{
	if( number == VertexNum::VERT_1 )
		m_P1 = vertex;
	else if( number == VertexNum::VERT_2 )
		m_P2 = vertex;
	else if( number == VertexNum::VERT_3 )
		m_P3 = vertex;
	else
		throw std::out_of_range{ "Chosen vertex does not exist!\n" };

	std::vector<GLfloat> vertices =
	{
		m_P1.x, m_P1.y, m_P1.z,
		m_P2.x, m_P2.y, m_P2.z,
		m_P3.x, m_P3.y, m_P3.z
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
}

void TriangleShape::SetVertices( const Position& p1, const Position& p2, const Position& p3 )
{
	m_P1 = p1;
	m_P2 = p2;
	m_P3 = p3;

	std::vector<GLfloat> vertices =
	{
		m_P1.x, m_P1.y, m_P1.z,
		m_P2.x, m_P2.y, m_P2.z,
		m_P3.x, m_P3.y, m_P3.z
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
}

void TriangleShape::SetColour( const Colour& colour )
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

const Position& TriangleShape::GetVertex( int number ) const
{
	if( number == VertexNum::VERT_1 )
		return m_P1;
	else if( number == VertexNum::VERT_2 )
		return m_P2;
	else if( number == VertexNum::VERT_3 )
		return m_P3;
	else
		throw std::out_of_range{ "Chosen vertex does not exist!\n" };
}

const Colour& TriangleShape::GetColour( ) const
{
	return m_Colour;
}
