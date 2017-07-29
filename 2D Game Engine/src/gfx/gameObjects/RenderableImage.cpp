#include "RenderableImage.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

RenderableImage::RenderableImage( const Position & position, const GLf_Size & size, const Colour & colour, unsigned short type )
	: RenderableImage( position, size, colour, type )
{
	textureRect = FloatRect( 0.0f, 0.0f, 1.0f, 1.0f );

	std::vector< GLfloat > vertices =
	{
		0.0f, 0.0f, 0.0f,
		0.0f, size.y, 0.0f,
		size.x, size.y, 0.0f,
		size.x, 0.0f, 0.0f
	};

	std::vector< GLfloat > colours =
	{
		colour.r, colour.g, colour.b, colour.a,
		colour.r, colour.g, colour.b, colour.a,
		colour.r, colour.g, colour.b, colour.a,
		colour.r, colour.g, colour.b, colour.a
	};

	std::vector< GLfloat > TexCoords =
	{
		textureRect.x, textureRect.y,
		textureRect.x, textureRect.y + textureRect.dy,
		textureRect.x + textureRect.dx, textureRect.y + textureRect.dy,
		textureRect.x + textureRect.dx, textureRect.y
	};

	vertVBO		= VertexBuffer( vertices, vertices.size( ), 3, VertexBuffer::BufferUsage::DYNAMIC );
	colourVBO	= VertexBuffer( colours, colours.size( ), 4, VertexBuffer::BufferUsage::DYNAMIC );
	texCoordVBO = VertexBuffer( TexCoords, TexCoords.size( ), 2, VertexBuffer::BufferUsage::DYNAMIC );

	VAO.BindBuffer( vertVBO, ShaderLocation::POSITION, 0, 0 );
	VAO.BindBuffer( colourVBO, ShaderLocation::COLOUR, 0, 0 );
	VAO.BindBuffer( texCoordVBO, ShaderLocation::TEXTURE_COORD, 0, 0 );

	std::vector<GLuint> indices = { 0, 1, 2, 0, 2, 3 };
	IBO = IndexBuffer( indices, indices.size( ), IndexBuffer::BufferUsage::DYNAMIC );
}

void RenderableImage::Render( Shader & shader )
{
	shader.SetUniform1i( "useFont", true );
	shader.SetUniform1i( "font", 0 );

	VAO.Bind( );

	glm::mat4 model;
	model = glm::translate( model, static_cast< glm::vec3 >( position ) );

	Renderable::RenderIndices( );

	shader.SetUniform1i( "useFont", false );
}

void RenderableImage::SetPosition( const Position & position )
{
	this->position = position;
}

void RenderableImage::SetSize( const GLf_Size & size )
{
	this->size = size;
}

void RenderableImage::SetColour( const Colour & colour )
{
	this->colour = colour;

	std::vector< GLfloat > colours =
	{
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a,
		this->colour.r, this->colour.g, this->colour.b, this->colour.a
	};

	colourVBO = VertexBuffer( colours, colours.size( ), 4, VertexBuffer::BufferUsage::DYNAMIC );
	VAO.BindBuffer( colourVBO, ShaderLocation::COLOUR, 0, 0 );
}

void RenderableImage::SetTextureRect( const FloatRect& rect )
{
	this->textureRect = rect;

	std::vector< GLfloat > TexCoords =
	{
		textureRect.x, textureRect.y,
		textureRect.x, textureRect.y + textureRect.dy,
		textureRect.x + textureRect.dx, textureRect.y + textureRect.dy,
		textureRect.x + textureRect.dx, textureRect.y
	};

	texCoordVBO = VertexBuffer( TexCoords, TexCoords.size( ), 2, VertexBuffer::BufferUsage::DYNAMIC );
	VAO.BindBuffer( texCoordVBO, ShaderLocation::TEXTURE_COORD, 0, 0 );
}
