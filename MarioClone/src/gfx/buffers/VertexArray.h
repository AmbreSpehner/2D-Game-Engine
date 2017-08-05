#pragma once

#include <memory>

#include "VertexBuffer.h"
#include "IndexBuffer.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void BindBuffer( const VertexBuffer& buffer, GLuint index, GLsizei stride, GLint offset );

	void Bind() const;
	void Unbind() const;

	VertexArray& operator=( VertexArray&& vArray )
	{
		glDeleteVertexArrays( 1, &arrayID );
		arrayID = vArray.arrayID;
		vArray.arrayID = 0;

		return *this;
	}

private:
	GLuint arrayID;
};