#include "IndexBuffer.h"

IndexBuffer::IndexBuffer( std::vector<GLuint>& data, GLuint count )
	:
	count( count )
{
	glGenBuffers( 1, &indexBufferID );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBufferID );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( GLuint ) * count, &data.front(), GL_STATIC_DRAW );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

IndexBuffer::~IndexBuffer()
{
	if ( indexBufferID != 0 )
	{
		glDeleteBuffers( 1, &indexBufferID );
	}
}

void IndexBuffer::Bind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBufferID );
}

void IndexBuffer::Unbind() const
{
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

GLuint IndexBuffer::GetCount() const
{
	return count;
}