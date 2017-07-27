#pragma once

#include <vector>

#include <GL/glew.h>

class IndexBuffer
{
public:
	IndexBuffer() = default;
	IndexBuffer( std::vector<GLuint>& data, GLuint count );
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	GLuint GetCount() const;

	IndexBuffer& operator=( IndexBuffer&& buffer )
	{
		glDeleteBuffers( 1, &indexBufferID );
		
		indexBufferID = buffer.indexBufferID;
		buffer.indexBufferID = 0;

		count = buffer.count;
		buffer.count = 0;

		return *this;
	}

private:
	GLuint indexBufferID;
	GLuint count;
};