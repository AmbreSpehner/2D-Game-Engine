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
	 *	@brief	Create a rectangle.
	 *	
	 *	Create a rectangle.
	 *
	 *	@param	X, position x of the rectangle
	 *	@param	Y, position y of the rectangle
	 *	@param	DX, width of the rectangle
	 *	@param	DY, height of the rectangle
	 */
	void SetRect( T X, T Y, T DX, T DY )
	{
		x = X;
		y = Y;
		dx = DX;
		dy = DY;
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