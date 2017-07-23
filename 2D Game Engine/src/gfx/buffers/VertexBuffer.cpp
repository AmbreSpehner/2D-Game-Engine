/**
 *	@file	VertexBuffer.cpp
 *	@author	BouwnLaw
 *	@date	08/07/2017
 *	@brief	Create a vertex buffer object.
 *
 *	Create a vertex buffer object to process all vertices given.
 */
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer( std::vector<GLfloat>& data, GLuint count, GLuint componentCount )
	:
	m_Count( count ),
	m_ComponentCount( componentCount )
{
	glGenBuffers( 1, &m_VertexBufferID );
	glBindBuffer( GL_ARRAY_BUFFER, m_VertexBufferID );
	glBufferData( GL_ARRAY_BUFFER, sizeof( GLfloat ) * count, &data.front(), GL_STATIC_DRAW );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

VertexBuffer::~VertexBuffer()
{
	if ( m_VertexBufferID != 0 )
	{
		glDeleteBuffers( 1, &m_VertexBufferID );
	}
}

void VertexBuffer::Bind() const
{
	glBindBuffer( GL_ARRAY_BUFFER, m_VertexBufferID );
}

void VertexBuffer::Unbind() const
{
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

GLuint VertexBuffer::GetComponentCount() const
{
	return m_ComponentCount;
}