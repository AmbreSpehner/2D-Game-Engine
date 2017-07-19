/**
 *	@file	VertexBuffer.h
 *	@author	BouwnLaw
 *	@date	08/07/2017
 *	@brief	Create a vertex buffer object.
 *
 *	Create a vertex buffer object to process all vertices given.
 */
#pragma once

// Include STL
#include <vector>

// Include Deps
#include <GL/glew.h>

/**
 *	@brief	Create a vertex buffer object.
 *
 *	Create a vertex buffer object to process all vertices given.
 */
class VertexBuffer
{
public:
	/**
	 *	@brief Default constructor.
	 *
	 *	Default constructor.
	 */
	VertexBuffer() = default;
	/**
	 *	@brief Constructor to generate the buffer.
	 *
	 *	Create a buffer and bind the data ( vertices ) to the buffer.
	 *
	 *	@param	data, reference to a vector of vertices
	 *	@param	count, number of vertices in the vector
	 *	@param	componentCount, number of component within the vector
	 */
	VertexBuffer( std::vector<GLfloat>& data, GLuint count, GLuint componentCount );
	/**
	 *	@brief	Destructor.
	 *
	 *	Delete the buffers.
	 */
	~VertexBuffer();

	/**
	 *	@brief	Bind the buffer.
	 *
	 *	Bind the buffer.
	 */
	void Bind() const;
	/**
	 *	@brief	Unbind the buffer.
	 *
	 *	Unbind the buffer.
	 */
	void Unbind() const;

	/**
	 *	@brief	Get the number of component in the buffer.
	 *
	 *	Get the number of component in the buffer
	 *
	 *	@return GLuint, componentCount
	 */
	GLuint GetComponentCount() const;

	/**
	 *	@brief Override of the '=' operator.
	 *
	 *	Override of the '=' operator and use of move semantics
	 *	to assing Vertex buffer to each other.
	 *
	 *	@return	VertexBuffer
	 */
	VertexBuffer& operator=( VertexBuffer&& buffer )
	{
		glDeleteBuffers( 1, &m_VertexBufferID );

		m_VertexBufferID = buffer.m_VertexBufferID;
		buffer.m_VertexBufferID = 0;

		m_ComponentCount = buffer.m_ComponentCount;
		buffer.m_ComponentCount = 0;

		return *this;
	}

private:
	GLuint m_VertexBufferID;
	GLuint m_ComponentCount;
};