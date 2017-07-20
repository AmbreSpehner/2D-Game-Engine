/**
 *	@file	Rect.h
 *	@author	Bouwnlaw
 *	@date	08/07/2017
 *	@brief	Rectangle.
 *
 *	Creates a rectangle with bounds.
 */

#pragma once

// Include STL
#include <glm/vec2.hpp>

/**
 *	@brief	Create a rectangle with public bounds.
 *
 *	Create a rectangle with public bounds that can is templated
 *	to support multiple fundamental types. 
 */
template<typename T>
class Rect
{
public:
	/**
	 *	@brief	Default constructor.
	 *	
	 *	Default constructor.
	 */
	Rect() = default;
	/**
	 *	@brief Constructor.
	 *
	 *	Create the rectangle.
	 *
	 *	@param	X, position x of the rectangle
	 *	@param	Y, position y of the rectangle
	 *	@param	DX, width of the rectangle
	 *	@param	DY, height of the rectangle
	 */
	Rect( T X, T Y, T DX, T DY )
		: 
		x( X ), y( Y ),
		dx( DX ), dy( DY )
	{

	}

	/**
	 *	@brief	Constructor.
	 *
	 *	Create the rectangle.
	 *
	 *	@param	position, the xy vector of the rectangle
	 *	@param	size, the width and height vector of the rectangle
	 */
	Rect( glm::vec2& position, glm::vec2& size )
		: Rect( position.x, position.y, size.x, size.y )
	{

	}

	/**
	 *	@brief	Set the rectangle.
	 *	
	 *	Set the rectangle.
	 *
	 *	@param	X, position x of the rectangle
	 *	@param	Y, position y of the rectangle
	 *	@param	DX, width of the rectangle
	 *	@param	DY, height of the rectangle
	 */
	void SetRect( const T X, const T Y, const T DX, const T DY )
	{
		x = X;
		y = Y;
		dx = DX;
		dy = DY;
	}

	/**
	 *	@brief	Set the rectangle.
	 *
	 *	Set the rectangle.
	 *
	 *	@param	position, position of the rectangle
	 *	@param	size, size of the rectangle
	 */
	void SetRect( const glm::vec3& position, const glm::vec2& size )
	{
		position.x = x;
		position.y = y;
		size.x = dx;
		size.y = dy;
	}

	/**
	 *	@brief	Set the position of the rectangle.
	 *
	 *	Set the position of the rectangle.
	 *
	 *	@param	X, position on the x-axis of the rectangle
	 *	@param	Y, position on the y-axis of the rectangle
	 */
	void SetPosition( const T X, const T Y )
	{
		X = x;
		Y = y;
	}

	/**
	 *	@brief	Set the position of the rectangle.
	 *
	 *	Set the position of the rectangle.
	 *
	 *	@param	position, position of the rectangle
	 */
	void SetPosition( const glm::vec3& position )
	{
		position.x = x;
		position.y = y;
	}

	/**
	 *	@brief	Set the size of the rectangle.
	 *
	 *	Set the size of the rectangle.
	 *
	 *	@param	DX, width of the rectangle
	 *	@param	DY, height of the rectangle
	 */
	void SetSize( const T DX, const T DY )
	{
		DX = dx;
		DY = dy;
	}

	/**
	 *	@brief	Set the size of the rectangle.
	 *
	 *	Set the size of the rectangle.
	 *
	 *	@param	size, size of the rectangle
	 */
	void SetSize( const glm::vec2& size )
	{
		size.x = x;
		size.y = y;
	}

	/**
	 *	@brief	Get the position of the rectangle.
	 *
	 *	Get the position of the rectangle in 3D.
	 *
	 *	@return	glm::vec3 position
	 */
	const glm::vec3& GetPosition( ) const
	{
		return glm::vec3( x, y, 0 );
	}

	/**
	 *	@brief	Get the size of the rectangle.
	 *
	 *	Get the size of the rectangle
	 *
	 *	@return	glm::vec2 size
	 */
	const glm::vec2& GetSize( ) const
	{
		return glm::vec2( dx, dy );
	}

	/**
	 *	@brief	Get the center of the rectangle.
	 *
	 *	Get the center of the rectangle.
	 *
	 *	@return	glm::vec2 result
	 */
	glm::vec2& GetCenter() const
	{
		return glm::vec2( ( x + dx ) / 2.0f, ( y + dy ) / 2.0f );
	}

public:
	T x, y;
	T dx, dy;
};

/**
 *	@brief Predefined float rectangle.
 *
 *	Predefined float rectangle of the class Rect.
 */
typedef Rect<float> FloatRect;
/**
 *	@brief Predefined int rectangle.
 *
 *	Predefined int rectangle of the class Rect.
 */
typedef Rect<int> IntRect;