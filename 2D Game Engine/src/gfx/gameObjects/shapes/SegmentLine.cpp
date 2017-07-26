#include "SegmentLine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

SegmentLine::SegmentLine( const Position& p1, const Position& p2, const Colour& colour, unsigned short type )
	:
	Renderable( p1, p2, colour, type )
{
	std::vector<GLfloat> vertices =
	{
		m_P1.x, m_P1.y, m_P1.z,
		m_P2.x, m_P2.y, m_P2.z
	};

	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_ColourVBO = VertexBuffer( colours, colours.size( ), 4 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );

	m_VerticesCount = vertices.size( ) / m_VertVBO.GetComponentCount( );
}

void SegmentLine::Render( Shader & shader )
{
	m_VAO.Bind( );

	Renderable::RenderVertices( );
}

void SegmentLine::SetLineWidth( float lineWidth )
{
	m_LineWidth = lineWidth;

	glLineWidth( m_LineWidth );
}

void SegmentLine::SetPoint( const Position & p, int number )
{
	if( number == VertexNum::P1 )
		m_P1 = p;
	else if( number == VertexNum::P2 )
		m_P2 = p;
	else
		throw std::out_of_range{ "Chosen vertex does not exist!\n" };

	std::vector<GLfloat> vertices =
	{
		m_P1.x, m_P1.y, m_P1.z,
		m_P2.x, m_P2.y, m_P2.z
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
}

void SegmentLine::SetPoints( const Position & p1, const Position & p2 )
{
	m_P1 = p1;
	m_P2 = p2;

	std::vector<GLfloat> vertices =
	{
		m_P1.x, m_P1.y, m_P1.z,
		m_P2.x, m_P2.y, m_P2.z
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
}

void SegmentLine::SetColour( const Colour & colour )
{
	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a
	};

	m_ColourVBO = VertexBuffer( colours, colours.size( ), 4 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );
}
