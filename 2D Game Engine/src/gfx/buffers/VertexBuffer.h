#pragma once

#include <vector>

#include <GL/glew.h>

class VertexBuffer
{
public:
	VertexBuffer() = default;
	VertexBuffer( std::vector<GLfloat>& data, GLuint count, GLuint componentCount, GLubyte usageType = 0 );
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

	GLuint GetComponentCount() const;

	VertexBuffer& operator=( VertexBuffer&& buffer )
	{
		glDeleteBuffers( 1, &vertexBufferID );

		vertexBufferID = buffer.vertexBufferID;
		buffer.vertexBufferID = 0;

		componentCount = buffer.componentCount;
		buffer.componentCount = 0;

		return *this;
	}

public:
	enum BUFFER_USAGE
	{
		STATIC	= 0,
		DYNAMIC = 1
	};

private:
	GLuint vertexBufferID;
	GLuint componentCount;
	GLuint count;

	GLubyte usageType;
};