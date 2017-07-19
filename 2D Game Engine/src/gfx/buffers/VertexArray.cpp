/**
 *	@file	VertexArray.cpp
 *	@author	BouwnLaw
 *	@date	08/07/2017
 *	@brief	Create a Vertex Array object.
 *
 *	Create a vertex array object.
 */
#include "VertexArray.h"


VertexArray::VertexArray()
{
	glGenVertexArrays( 1, &m_ArrayID );
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays( 1, &m_ArrayID );
}

void VertexArray::BindBuffer( const VertexBuffer& buffer, GLuint index, GLsizei stride, GLint offset )
{
	Bind();
	buffer.Bind();

	glVertexAttribPointer( index, buffer.GetComponentCount(), GL_FLOAT, GL_FALSE, stride, ( GLvoid* ) offset );
	glEnableVertexAttribArray( index );

	buffer.Unbind();
}

void VertexArray::Bind() const
{
	glBindVertexArray( m_ArrayID );
}

void VertexArray::Unbind() const
{
	glBindVertexArray( 0 );
}
