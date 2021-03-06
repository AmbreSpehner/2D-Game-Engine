#include "TriangleShape.h"

#include <vector>

#include <stdexcept>

TriangleShape::TriangleShape( const Point<GLfloat>& p1, const Point<GLfloat>& p2, const Point<GLfloat>& p3, const Colour& colour, unsigned short type )
	:
	Renderable( p1, p2, p3, colour, type )
{
	std::vector<GLfloat> vertices =
	{
		this->p1.x, this->p2.y, this->p3.z,
		this->p2.x, this->p2.y, this->p2.z,
		this->p3.x, this->p3.y, this->p3.z
	};

	std::vector<GLfloat> colours =
	{
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a
	};

	vertVBO = VertexBuffer( vertices, vertices.size( ), 3, VertexBuffer::BufferUsage::STATIC );
	colourVBO = VertexBuffer( colours, colours.size( ), 4, VertexBuffer::BufferUsage::STATIC );

	VAO.BindBuffer( vertVBO, ShaderLocation::POSITION, 0, 0 );
	VAO.BindBuffer( colourVBO, ShaderLocation::COLOUR, 0, 0 );

	verticesCount = vertices.size( ) / vertVBO.GetComponentCount( );
}

void TriangleShape::Render( Shader& shader )
{
	VAO.Bind( );

	glm::mat4 model;
	model = glm::translate( model, glm::vec3( 0, 0, 0 ) );
	
	shader.SetUniformMat4f( "model", model );

	Renderable::RenderVertices( );
}

void TriangleShape::SetVertex( const Point<GLfloat>& vertex, int index )
{
	if( index == VertexNum::P1 )
		p1 = vertex;
	else if( index == VertexNum::P2 )
		p2 = vertex;
	else if( index == VertexNum::P3 )
		p3 = vertex;
	else
		throw std::out_of_range{ "Chosen vertex does not exist!\n" };

	std::vector<GLfloat> vertices =
	{
		p1.x, p1.y, p1.z,
		p2.x, p2.y, p2.z,
		p3.x, p3.y, p3.z
	};

	vertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	VAO.BindBuffer( vertVBO, ShaderLocation::POSITION, 0, 0 );
}

void TriangleShape::SetVertices( const Point<GLfloat>& p1, const Point<GLfloat>& p2, const Point<GLfloat>& p3 )
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;

	std::vector<GLfloat> vertices =
	{
		this->p1.x, this->p1.y, this->p1.z,
		this->p2.x, this->p2.y, this->p2.z,
		this->p3.x, this->p3.y, this->p3.z
	};

	vertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	VAO.BindBuffer( vertVBO, ShaderLocation::POSITION, 0, 0 );
}

void TriangleShape::SetColour( const Colour& colour )
{
	this->colour = colour;

	std::vector<GLfloat> colours =
	{
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a
	};

	colourVBO = VertexBuffer( colours, colours.size( ), 4 );
	VAO.BindBuffer( colourVBO, ShaderLocation::COLOUR, 0, 0 );
}

const Point<GLfloat>& TriangleShape::GetVertex( int number ) const
{
	if( number == VertexNum::P1 )
		return p1;
	else if( number == VertexNum::P2 )
		return p2;
	else if( number == VertexNum::P3 )
		return p3;
	else
		throw std::out_of_range{ "Chosen vertex does not exist!\n" };
}
