#include "Sprite.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

Sprite::Sprite( const Position& position, std::shared_ptr<Texture> pTexture )
	:
	Renderable( position, pTexture->GetSize() ),
	pTexture( pTexture )
{
	textureRect.SetRect( 0.0f, 0.0f, 1.0f, 1.0f );

	std::vector<GLfloat> vertices =
	{
		0.0f, 0.0f, 0.0f,
		0.0f, this->pTexture->GetSize().y, 0.0f,
		this->pTexture->GetSize().x, this->pTexture->GetSize().y, 0.0f,
		this->pTexture->GetSize().x, 0.0f, 0.0f
	};

	std::vector<GLfloat> textVert =
	{
		textureRect.x, textureRect.y,
		textureRect.x, textureRect.y + textureRect.dy,
		textureRect.x + textureRect.dx, textureRect.y + textureRect.dy,
		textureRect.x + textureRect.dx, textureRect.y
	};

	vertVBO = VertexBuffer( vertices, vertices.size(), 3 );
	texCoordVBO = VertexBuffer( textVert, textVert.size(), 2 );

	VAO.BindBuffer( vertVBO, ShaderLocation::POSITION, 0, 0 );
	VAO.BindBuffer( texCoordVBO, ShaderLocation::TEXTURE_COORD, 0, 0 );

	std::vector<GLuint> indices = { 0, 1, 2, 0, 2, 3 };
	IBO = IndexBuffer( indices, indices.size() );
}

Sprite::Sprite( const Position& position, const GLf_Size& size, std::shared_ptr<Texture> pTexture )
	: 
	Renderable( position, size ),
	pTexture( pTexture )
{
	textureRect.SetRect( 0.0f, 0.0f, 1.0f, 1.0f );	

	std::vector<GLfloat> vertices =
	{
		0.0f, 0.0f, 0.0f,
		0.0f, this->size.y, 0.0f,
		this->size.x, this->size.y, 0.0f,
		this->size.x, 0.0f, 0.0f
	};

	std::vector<GLfloat> textVert =
	{
		textureRect.x, textureRect.y,
		textureRect.x, textureRect.y + textureRect.dy,
		textureRect.x + textureRect.dx, textureRect.y + textureRect.dy,
		textureRect.x + textureRect.dx, textureRect.y
	};

	vertVBO = VertexBuffer( vertices, vertices.size(), 3 );
	texCoordVBO = VertexBuffer( textVert, textVert.size(), 2 );

	VAO.BindBuffer( vertVBO, ShaderLocation::POSITION, 0, 0 );
	VAO.BindBuffer( texCoordVBO, ShaderLocation::TEXTURE_COORD, 0, 0 );

	std::vector<GLuint> indices = { 0, 1, 2, 0, 2, 3 };
	IBO = IndexBuffer( indices, indices.size() );
}

void Sprite::Render( Shader& shader )
{
	shader.SetUniform1i( "useTexture", true );
	shader.SetUniform1i( "colourTexture", 0 );

	VAO.Bind();

	glActiveTexture( GL_TEXTURE0 );
	pTexture->Bind();

	glm::mat4 model;
	model = glm::translate( model, static_cast<glm::vec3>( position ) );
	
	shader.SetUniformMat4f( "model", model );

	Renderable::RenderIndices();

	shader.SetUniform1i( "useTexture", false );
}

void Sprite::SetPosition( Position& position )
{
	this->position = position;
}

void Sprite::SetSize( GLf_Size& size )
{
	this->size = size;

	std::vector<GLfloat> vertices =
	{
		0, 0, 0,
		0, this->size.y, 0,
		this->size.x, this->size.y, 0,
		this->size.x, 0, 0
	};

	vertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	VAO.BindBuffer( vertVBO, ShaderLocation::POSITION, 0, 0 );
}

void Sprite::SetColour( Colour& colour )
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

void Sprite::SetTexture( std::shared_ptr<Texture> pTexture )
{
	this->pTexture = pTexture;
}

void Sprite::ScaleSprite( float scale )
{
	this->scale = scale;

	SetSize( GLf_Size( size.x * scale, size.y * scale ) );
}

void Sprite::SetTextureRect( const FloatRect& rect )
{
	textureRect.SetRect( rect.x, rect.y, rect.dx, rect.dy );

	SetSize( GLf_Size( rect.dx * scale, rect.dy * scale ) );
	SetTextCoords( textureRect.x, textureRect.y, textureRect.dx, textureRect.dy );
}

void Sprite::SetTextureRect( float x, float y, float dx, float dy )
{
	textureRect.SetRect( x / pTexture->GetSize( ).x, y / pTexture->GetSize( ).y,
						   dx / pTexture->GetSize( ).x, dy / pTexture->GetSize( ).y );

	SetSize( GLf_Size( dx * scale, dy * scale ) );
	SetTextCoords( textureRect.x, textureRect.y, textureRect.dx, textureRect.dy );
}

void Sprite::SetTextureRect( const Position& position, const GLf_Size& size )
{
	SetTextureRect( position.x, position.y, size.x, size.y );
}

void Sprite::SetTextCoords( const float x, const float y, const float dx, const float dy )
{
	std::vector<GLfloat> textVert =
	{
		x, y,
		x, y + dy,
		x + dx, y + dy,
		x + dx, y
	};

	texCoordVBO = VertexBuffer( textVert, textVert.size( ), 2 );

	VAO.BindBuffer( texCoordVBO, ShaderLocation::TEXTURE_COORD, 0, 0 );
}

void Sprite::SetTextCoords( const Position& position, const GLf_Size& size )
{
	SetTextCoords( position.x, position.y, size.x, size.y );
}