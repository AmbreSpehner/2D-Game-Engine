#include "Sprite.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

Sprite::Sprite( const Position& position, std::shared_ptr<Texture> pTexture )
	:
	Renderable( position, pTexture->GetSize() ),
	m_pTexture( pTexture )
{
	m_TextureRect.SetRect( 0.0f, 0.0f, 1.0f, 1.0f );

	std::vector<GLfloat> vertices =
	{
		0.0f, 0.0f, 0.0f,
		0.0f, m_pTexture->GetSize().y, 0.0f,
		m_pTexture->GetSize().x, m_pTexture->GetSize().y, 0.0f,
		m_pTexture->GetSize().x, 0.0f, 0.0f
	};

	std::vector<GLfloat> textVert =
	{
		m_TextureRect.x, m_TextureRect.y,
		m_TextureRect.x, m_TextureRect.y + m_TextureRect.dy,
		m_TextureRect.x + m_TextureRect.dx, m_TextureRect.y + m_TextureRect.dy,
		m_TextureRect.x + m_TextureRect.dx, m_TextureRect.y
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size(), 3 );
	m_TexCoordVBO = VertexBuffer( textVert, textVert.size(), 2 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_TexCoordVBO, ShaderLocation::TEXTURE_COORD, 0, 0 );

	std::vector<GLuint> indices = { 0, 1, 2, 0, 2, 3 };
	m_IBO = IndexBuffer( indices, indices.size() );
}

Sprite::Sprite( const Position& position, const Size& size, std::shared_ptr<Texture> pTexture )
	: 
	Renderable( position, size ),
	m_pTexture( pTexture )
{
	m_TextureRect.SetRect( 0.0f, 0.0f, 1.0f, 1.0f );	

	std::vector<GLfloat> vertices =
	{
		0.0f, 0.0f, 0.0f,
		0.0f, m_Size.y, 0.0f,
		m_Size.x, m_Size.y, 0.0f,
		m_Size.x, 0.0f, 0.0f
	};

	std::vector<GLfloat> textVert =
	{
		m_TextureRect.x, m_TextureRect.y,
		m_TextureRect.x, m_TextureRect.y + m_TextureRect.dy,
		m_TextureRect.x + m_TextureRect.dx, m_TextureRect.y + m_TextureRect.dy,
		m_TextureRect.x + m_TextureRect.dx, m_TextureRect.y
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size(), 3 );
	m_TexCoordVBO = VertexBuffer( textVert, textVert.size(), 2 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_TexCoordVBO, ShaderLocation::TEXTURE_COORD, 0, 0 );

	std::vector<GLuint> indices = { 0, 1, 2, 0, 2, 3 };
	m_IBO = IndexBuffer( indices, indices.size() );
}

void Sprite::Render( Shader& shader )
{
	shader.SetUniform1i( "useTexture", true );
	shader.SetUniform1i( "colourTexture", 0 );

	m_VAO.Bind();

	glActiveTexture( GL_TEXTURE0 );
	m_pTexture->Bind();

	glm::mat4 model;
	// auto vec3 = m_Position.ToVec3( );
	model = glm::translate( model, m_Position.ToVec3() );
	
	shader.SetUniformMat4f( "model", model );

	Renderable::RenderIndices();

	shader.SetUniform1i( "useTexture", false );
}

void Sprite::SetPosition( Position& position )
{
	m_Position = position;
}

void Sprite::SetSize( Size& size )
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

void Sprite::SetColour( Colour& colour )
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

void Sprite::SetTexture( std::shared_ptr<Texture> pTexture )
{
	m_pTexture = pTexture;
}

void Sprite::ScaleSprite( float scale )
{
	m_Scale = scale;

	SetSize( Size( m_Size.x * m_Scale, m_Size.y * m_Scale ) );
}

void Sprite::SetTextureRect( const FloatRect& rect )
{
	m_TextureRect.SetRect( rect.x, rect.y, rect.dx, rect.dy );

	SetSize( Size( rect.dx * m_Scale, rect.dy * m_Scale ) );
	SetTextCoords( m_TextureRect.x, m_TextureRect.y, m_TextureRect.dx, m_TextureRect.dy );
}

void Sprite::SetTextureRect( float x, float y, float dx, float dy )
{
	m_TextureRect.SetRect( x / m_pTexture->GetSize( ).x, y / m_pTexture->GetSize( ).y,
						   dx / m_pTexture->GetSize( ).x, dy / m_pTexture->GetSize( ).y );

	SetSize( Size( dx * m_Scale, dy * m_Scale ) );
	SetTextCoords( m_TextureRect.x, m_TextureRect.y, m_TextureRect.dx, m_TextureRect.dy );
}

void Sprite::SetTextureRect( const Position& position, const Size& size )
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

	m_TexCoordVBO = VertexBuffer( textVert, textVert.size( ), 2 );

	m_VAO.BindBuffer( m_TexCoordVBO, ShaderLocation::TEXTURE_COORD, 0, 0 );
}

void Sprite::SetTextCoords( const Position& position, const Size& size )
{
	SetTextCoords( position.x, position.y, size.x, size.y );
}