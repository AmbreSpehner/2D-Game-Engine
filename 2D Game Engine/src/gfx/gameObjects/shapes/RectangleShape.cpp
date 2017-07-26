#include "RectangleShape.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

RectangleShape::RectangleShape( const Position& position, const GLf_Size& size, const Colour& colour )
	: Renderable( position, size, colour )
{
	std::vector<GLfloat> vertices =
	{
		0, 0, 0,			
		0, m_Size.y, 0,			
		m_Size.x, m_Size.y, 0,	
		m_Size.x, 0, 0			
	};

	std::vector<GLfloat> colours =
	{
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,	
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,	
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a,	
		m_Colour.r, m_Colour.g, m_Colour.b, m_Colour.a	
	};

	m_VertVBO = VertexBuffer( vertices, vertices.size(), 3 );
	m_ColourVBO = VertexBuffer( colours, colours.size(), 4 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );

	std::vector<GLuint> indices = { 0, 1, 2, 0, 2, 3 };
	m_IBO = IndexBuffer( indices, indices.size() );
}

void RectangleShape::Render( Shader& shader )
{
	m_VAO.Bind();

	glm::mat4 model;
	model = glm::translate( model, static_cast<glm::vec3>( m_Position ) );

	shader.SetUniformMat4f( "model", model );

	Renderable::RenderIndices();
}

void RectangleShape::SetPosition( const Position& position )
{
	m_Position = position;
}

void RectangleShape::SetSize( const GLf_Size& size )
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

void RectangleShape::SetColour( const Colour& colour )
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
