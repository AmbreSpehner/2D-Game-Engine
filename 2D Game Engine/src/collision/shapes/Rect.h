#pragma once

#include <GL/glew.h>
#include <glm/vec2.hpp>

template<typename T>
class Rect
{
public:
	Rect() = default;
	Rect( const T x, const T y, const T dx, const T dy )
		: x( x ), y( y ), dx( dx ), dy( dy ) {	}
	Rect( const glm::vec2& position, const glm::vec2& size )
		: Rect( position.x, position.y, size.x, size.y ) {	}

	void SetRect( const T x, const T y, const T dx, const T dy )
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
	}

	void SetRect( const glm::vec3& position, const glm::vec2& size )
	{
		this->x = position.x;
		this->y = position.y;
		this->dx = size.x;
		this->dy = size.y;
	}

	void SetPosition( const T x, const T y )
	{
		this->x = x;
		this->y = y;
	}

	void SetPosition( const glm::vec3& position )
	{
		this->x = position.x;
		this->y = position.y;
	}

	void SetSize( const T dx, const T dy )
	{
		this->dx = dx;
		this->dy = dy;
	}

	void SetSize( const glm::vec2& size )
	{
		this->dx = size.x;
		this->dy = size.y;
	}

	const glm::vec3& GetPosition( ) const
	{
		return glm::vec3( x, y, 0 );
	}

	const glm::vec2& GetSize( ) const
	{
		return glm::vec2( dx, dy );
	}

	glm::vec2& GetCenter() const
	{
		return glm::vec2( ( x + dx ) / 2.0f, ( y + dy ) / 2.0f );
	}

public:
	T x, y;
	T dx, dy;
};

typedef Rect<GLfloat> GLf_Rect;
typedef Rect<GLint> GLi_Rect;
typedef Rect<float> FloatRect;
typedef Rect<int> IntRect;