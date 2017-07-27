#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays( 1, &arrayID );
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays( 1, &arrayID );
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
	glBindVertexArray( arrayID );
}

void VertexArray::Unbind() const
{
	glBindVertexArray( 0 );
}
