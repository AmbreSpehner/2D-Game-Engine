#pragma once

#include <vector>

#include <GL/glew.h>

class IndexBuffer
{
public:
	IndexBuffer() = default;
	IndexBuffer( std::vector<GLuint>& data, GLuint count, GLubyte usageType = 0 );
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

public:
	enum BufferUsage
	{
		STATIC	= 0,
		DYNAMIC = 1
	};

private:
	GLuint indexBufferID;
	GLuint count;

	GLubyte usageType;
};