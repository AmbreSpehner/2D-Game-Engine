#include "RectangleShape.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

RectangleShape::RectangleShape( const Position& position, const GLf_Size& size, const Colour& colour, unsigned short type )
	: Renderable( position, size, colour, type )
{
	std::vector<GLfloat> vertices =
	{
		0, 0, 0,
		0, 1, 0,
		1, 1, 0,
		1, 0, 0
	};

	std::vector<GLfloat> colours =
	{
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a
	};

	vertVBO = VertexBuffer( vertices, vertices.size(), 3 );
	colourVBO = VertexBuffer( colours, colours.size(), 4 );

	VAO.BindBuffer( vertVBO, ShaderLocation::POSITION, 0, 0 );
	VAO.BindBuffer( colourVBO, ShaderLocation::COLOUR, 0, 0 );

	std::vector<GLuint> indices = { 0, 1, 2, 0, 2, 3 };
	IBO = IndexBuffer( indices, indices.size() );
}

void RectangleShape::Render( Shader& shader )
{
	VAO.Bind();

	glm::mat4 model;
	model = glm::translate( model, static_cast<glm::vec3>( position ) ) * glm::scale( model, glm::vec3( size.x, size.y, 0.0f ) );

	shader.SetUniformMat4f( "model", model );

	Renderable::RenderIndices();
}

void RectangleShape::SetPosition( const Position& position )
{
	this->position = position;
}

void RectangleShape::SetSize( const GLf_Size& size )
{
	this->size = size;
}

void RectangleShape::SetColour( const Colour& colour )
{
	this->colour = colour;

	std::vector<GLfloat> colours =
	{
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a
	};

	colourVBO = VertexBuffer( colours, colours.size( ), 4 );
	VAO.BindBuffer( colourVBO, ShaderLocation::COLOUR, 0, 0 );
}
