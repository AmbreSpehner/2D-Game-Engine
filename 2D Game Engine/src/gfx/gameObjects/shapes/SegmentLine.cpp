#include "SegmentLine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

SegmentLine::SegmentLine( const Point<GLfloat>& p1, const Point<GLfloat>& p2, const Colour& colour, unsigned short type )
	:
	Renderable( p1, p2, colour, type )
{	
	std::vector<GLfloat> vertices =
	{
		0.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 1.0f
	};

	std::vector<GLfloat> colours =
	{
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a
	};

	vertVBO = VertexBuffer( vertices, vertices.size( ), 3, VertexBuffer::BufferUsage::STATIC );
	colourVBO = VertexBuffer( colours, colours.size( ), 4, VertexBuffer::BufferUsage::STATIC );

	VAO.BindBuffer( vertVBO, ShaderLocation::POSITION, 0, 0 );
	VAO.BindBuffer( colourVBO, ShaderLocation::COLOUR, 0, 0 );

	verticesCount = vertices.size( ) / vertVBO.GetComponentCount( );
}

void SegmentLine::Render( Shader& shader )
{
	VAO.Bind( );

	glm::mat4 model;
	model = glm::translate( model, static_cast< glm::vec3 >( p1 ) ) * glm::scale( model, glm::vec3( p2.x / 2.0f, p2.y / 2.0f, p2.z ) );

	shader.SetUniformMat4f( "model", model );

	Renderable::RenderVertices( );
}

void SegmentLine::SetLineWidth( float lineWidth )
{
	this->lineWidth = lineWidth;

	glLineWidth( this->lineWidth );
}

void SegmentLine::SetPoint( const Point<GLfloat>& p, int index )
{
	if( index == VertexNum::P1 )
		p1 = p;
	else if( index == VertexNum::P2 )
		p2 = p;
	else
		throw std::out_of_range{ "Chosen vertex does not exist!\n" };
}

void SegmentLine::SetPoints( const Point<GLfloat>& p1, const Point<GLfloat>& p2 )
{
	this->p1 = p1;
	this->p2 = p2;
}

void SegmentLine::SetColour( const Colour& colour )
{
	this->colour = colour;

	std::vector<GLfloat> colours =
	{
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a
	};

	colourVBO = VertexBuffer( colours, colours.size( ), 4 );
	VAO.BindBuffer( colourVBO, ShaderLocation::COLOUR, 0, 0 );
}
