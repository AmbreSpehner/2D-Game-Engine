/**
 *	@file	RectangleShape.h
 *	@author	BouwnLaw
 *	@date	09/07/2017
 *	@brief	Create a rectangular shape.
 *
 *	Create a rectangular shape with a given position, size and colour.
 */

#pragma once

// Include Project
#include "../Renderable.h"

#include "../../buffers/VertexBuffer.h"
#include "../../buffers/IndexBuffer.h"

/**
 *	@brief	Create a rectangular shape.
 *
 *	Create a rectangular shape with a given position, size and colour.
 */
class RectangleShape : public Renderable
{
public:
	/**
	 *	@brief	Constructor.
	 *
	 *	Default Constructor.
	 */
	RectangleShape() = default;
	/**
	 *	@brief	Constructor.
	 *
	 *	Create the Rectangular shape.
	 *
	 *	@param	position, vec3 position of the shape
	 *	@param	size, vec2 size of the shape
	 *	@param	colour, vec4 colour of the shape
	 */
	RectangleShape( const glm::vec3& position, const glm::vec2& size, const glm::vec4& colour );
	/**
	*	@brief	Constructor.
	*
	*	Create the Rectangular shape.
	*
	*	@param	position, vec3 position of the shape
	*	@param	size, vec2 size of the shape
	*	@param	colour, vec4 colour of the shape
	*	@param	type, type of rendering
	*/
	RectangleShape( const glm::vec3& position, const glm::vec2& size, const glm::vec4& colour, int type );

	void Render( Shader& shader ) override;

	void SetPosition( const glm::vec3& position );
	void SetSize( const glm::vec2& size );
	void SetColour( const glm::vec4 colour );

	const glm::vec3& GetPosition( ) const { return m_Position; }
	const glm::vec2& GetSize( ) const { return m_Size; }
	const glm::vec4& GetColour( ) const { return m_Colour; }
};