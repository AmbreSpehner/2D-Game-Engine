#include "VertexBuffer.h"

VertexBuffer::VertexBuffer( std::vector<GLfloat>& data, GLuint count, GLuint componentCount )
	:
	count( count ),
	componentCount( componentCount )
{
	glGenBuffers( 1, &vertexBufferID );
	glBindBuffer( GL_ARRAY_BUFFER, vertexBufferID );
	glBufferData( GL_ARRAY_BUFFER, sizeof( GLfloat ) * count, &data.front(), GL_STATIC_DRAW );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

VertexBuffer::~VertexBuffer()
{
	if ( vertexBufferID != 0 )
	{
		glDeleteBuffers( 1, &vertexBufferID );
	}
}

void VertexBuffer::Bind() const
{
	glBindBuffer( GL_ARRAY_BUFFER, vertexBufferID );
}

void VertexBuffer::Unbind() const
{
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

GLuint VertexBuffer::GetComponentCount() const
{
	return componentCount;
}