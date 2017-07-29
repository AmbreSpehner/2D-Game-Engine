#include "IndexBuffer.h"

IndexBuffer::IndexBuffer( std::vector<GLuint>& data, GLuint count, GLubyte usageType )
	:
	count( count ),
	usageType( usageType )
{
	glGenBuffers( 1, &indexBufferID );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBufferID );
	
	if( this->usageType == BUFFER_USAGE::STATIC )
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( GLuint ) * count, &data.front( ), GL_STATIC_DRAW );
	else if( this->usageType == BUFFER_USAGE::DYNAMIC )
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( GLuint ) * count, &data.front( ), GL_DYNAMIC_DRAW );
	else
		throw std::out_of_range{ "The usage type does not exist!" };

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