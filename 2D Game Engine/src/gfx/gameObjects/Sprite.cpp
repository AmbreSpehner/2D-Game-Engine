/**
 *	@file	Sprite.cpp
 *	@author	BouwnLaw
 *	@date	09/07/2017
 *	@brief	Create a Sprite.
 *
 *	Create using Renderable.h as a base using a texture.
 */
#include "Sprite.h"

// Include Deps
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Sprite::Sprite( const glm::vec3 & position, std::shared_ptr<Texture> pTexture )
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

Sprite::Sprite( const glm::vec3& position, const glm::vec2& size, std::shared_ptr<Texture> pTexture )
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
	model = glm::translate( model, m_Position );
	shader.SetUniformMat4f( "model", model );

	Renderable::Render();

	shader.SetUniform1i( "useTexture", false );
}

void Sprite::AddTextureRect( float x, float y, float dx, float dy )
{
	std::vector<GLfloat> textVert =
	{
		x / m_pTexture->GetSize().x, y / m_pTexture->GetSize().y,
		x / m_pTexture->GetSize().x, ( y + dy ) / m_pTexture->GetSize().y,
		( x + dx ) / m_pTexture->GetSize().x, ( y + dy ) / m_pTexture->GetSize().y,
		( x + dx ) / m_pTexture->GetSize().x, y / m_pTexture->GetSize().y
	};

	m_TexCoordVBO = VertexBuffer( textVert, textVert.size(), 2 );

	m_VAO.BindBuffer( m_TexCoordVBO, ShaderLocation::TEXTURE_COORD, 0, 0 );
}