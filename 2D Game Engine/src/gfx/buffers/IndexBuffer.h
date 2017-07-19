/**
 *	@file	IndexBuffer.h
 *	@author	BouwnLaw
 *	@date	08/07/2017
 *	@brief	Create an index buffer object.
 *
 *	Create an index buffer object to process all indices given.
 */
#pragma once

// Include STL
#include <vector>

// Include Deps
#include <GL/glew.h>

/**
 *	@brief	Create an index buffer object.
 *
 *	Create an index buffer object to process all indices given.
 */
class IndexBuffer
{
public:
	/**
	 *	@brief Default constructor.
	 *
	 *	Default constructor.
	 */
	IndexBuffer() = default;
	/**
	 *	@brief Constructor to generate the buffer.
	 *
	 *	Create a buffer and bind the data ( indices ) to the buffer.
	 *
	 *	@param	data, reference to a vector of vertices
	 *	@param	count, number of indices in the vector
	 */
	IndexBuffer( std::vector<GLuint>& data, GLuint count );
	/**
	 *	@brief	Destructor.
	 *
	 *	Delete the buffers.
	 */
	~IndexBuffer();

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
	 *	@brief Get the number of indices in the buffer.
	 *
	 *	Retrieve the number of indices in the buffer.
	 */
	GLuint GetCount() const;

	/**
	 *	@brief Override of the '=' operator.
	 *
	 *	Override of the '=' operator and use of move semantics
	 *	to assing Index buffer to each other.
	 *
	 *	@return	IndexBuffer
	 */
	IndexBuffer& operator=( IndexBuffer&& buffer )
	{
		glDeleteBuffers( 1, &m_IndexBufferID );
		
		m_IndexBufferID = buffer.m_IndexBufferID;
		buffer.m_IndexBufferID = 0;

		m_Count = buffer.m_Count;
		buffer.m_Count = 0;

		return *this;
	}

private:
	GLuint m_IndexBufferID;
	GLuint m_Count;
};