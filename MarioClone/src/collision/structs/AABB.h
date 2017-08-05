#pragma once

#include <GL/glew.h>

#include "../../gfx/structs/Point.h"

template<typename T>
struct AABB
{
	AABB( ) = default;
	AABB( const Point<T>& centerPoint, const Point<T>& halfWidth, const Point<T>& halfHeight )
		: centerPoint( centerPoint ), halfWidth( halfWidth ), halfHeight( halfHeight )
	{	}

	Point<T> centerPoint;
	Point<T> halfWidth;
	Point<T> halfHeight;
};