#include "PolygonShape.h"

#include <iostream>

PolygonShape::PolygonShape( std::vector<glm::vec3>& vertPos, glm::vec4& colour )
	:
	m_VertPos( vertPos ),
	m_Colour( colour )
{
	std::vector<GLfloat> vertices;

	for( const auto& verts : m_VertPos )
	{
		vertices.insert( vertices.end(), glm::value_ptr( verts ), glm::value_ptr( verts ) + 3 );
	}

	std::cout << vertices.size( ) << '\n';

	std::vector<GLfloat> colours;

	for( int i = 0; i < vertices.size( ); i += 3 )
	{
		colours.emplace_back( m_Colour.r );
		colours.emplace_back( m_Colour.g );
		colours.emplace_back( m_Colour.b );
		colours.emplace_back( m_Colour.a );
	}

	m_VertVBO = VertexBuffer( vertices, vertices.size( ), 3 );
	m_ColourVBO = VertexBuffer( colours, colours.size( ), 4 );

	m_VAO.BindBuffer( m_VertVBO, ShaderLocation::POSITION, 0, 0 );
	m_VAO.BindBuffer( m_ColourVBO, ShaderLocation::COLOUR, 0, 0 );

	m_VerticesCount = vertices.size( ) / m_VertVBO.GetComponentCount( );
}

void PolygonShape::Render( )
{
	m_VAO.Bind( );

	glDrawArrays( GL_LINE_LOOP, 0, m_VerticesCount );
}
