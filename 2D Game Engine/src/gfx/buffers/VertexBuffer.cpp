#include "VertexBuffer.h"

VertexBuffer::VertexBuffer( std::vector<GLfloat>& data, GLuint count, GLuint componentCount, GLubyte usageType )
	:
	count( count ),
	componentCount( componentCount ),
	usageType( usageType )
{
	glGenBuffers( 1, &vertexBufferID );
	glBindBuffer( GL_ARRAY_BUFFER, vertexBufferID );

	if( this->usageType == BUFFER_USAGE::STATIC )
		glBufferData( GL_ARRAY_BUFFER, sizeof( GLfloat ) * count, &data.front( ), GL_STATIC_DRAW );
	else if( this->usageType = BUFFER_USAGE::DYNAMIC )
		glBufferData( GL_ARRAY_BUFFER, sizeof( GLfloat ) * count, &data.front( ), GL_DYNAMIC_DRAW );
	else
		throw std::out_of_range{ "The usage type does not exist!" };


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