/**
 *	@file	IndexBuffer.cpp
 *	@author	BouwnLaw
 *	@date	08/07/2017
 *	@brief	Create an index buffer object.
 *
 *	Create an index buffer object to process all indices given.
 */
#include "IndexBuffer.h"

// Include STL
#include <iostream>

IndexBuffer::IndexBuffer( std::vector<GLuint>& data, GLuint count )
	:
	m_Count( count )
{
	glGenBuffers( 1, &m_IndexBufferID );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( GLuint ) * count, &data.front(), GL_STATIC_DRAW );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

IndexBuffer::~IndexBuffer()
{
	if ( m_IndexBufferID != 0 )
	{
		glDeleteBuffers( 1, &m_IndexBufferID );
	}
}

void IndexBuffer::Bind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID );
}

void IndexBuffer::Unbind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

GLuint IndexBuffer::GetCount() const
{
	return m_Count;
}