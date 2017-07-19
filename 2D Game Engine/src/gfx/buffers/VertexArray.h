/**
 *	@file	VertexArray.h
 *	@author	BouwnLaw
 *	@date	08/07/2017
 *	@brief	Create a Vertex Array object.
 *
 *	Create a vertex array object.
 */

#pragma once

// Include STL
#include <memory>

// Include Project
#include "VertexBuffer.h"
#include "IndexBuffer.h"

/**
 *	@brief	Create a Vertex Array object.
 *
 *	Create a vertex array object.
 */
class VertexArray
{
public:
	/**
	 *	@brief	Constructor.
	 *	
	 *	Generate the vertex array.
	 */
	VertexArray();
	/**
	 *	@brief Destructor.
	 *
	 *	Delete the vertex array
	 */
	~VertexArray();

	/**
	 *	@brief	Bind the buffers to the Vertex array object.
	 *
	 *	Bind the buffer( vertex buffer, index buffer ) to the Vertex array object.
	 */
	void BindBuffer( const VertexBuffer& buffer, GLuint index, GLsizei stride, GLint offset );

	/**
	 *	@brief	Bind the vertex array.
	 * 
	 *	Bind the vertex array.
	 */
	void Bind() const;
	/**
	 *	@brief Unbind the vertex array.
	 *
	 *	Unbind the vertex array.
	 */
	void Unbind() const;

	/**
	 *	@brief Override of the '=' operator.
	 *
	 *	Override of the '=' operator and use of move semantics
	 *	to assing Vertex array to each other.
	 *
	 *	@return	VertexArray
	 */
	VertexArray& operator=( VertexArray&& vArray )
	{
		glDeleteVertexArrays( 1, &m_ArrayID );
		m_ArrayID = vArray.m_ArrayID;
		vArray.m_ArrayID = 0;

		return *this;
	}

private:
	GLuint m_ArrayID;
};