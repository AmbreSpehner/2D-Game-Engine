#pragma once

#include <GL/glew.h>

#include "../structs/AABB.h"

#include <iostream>

template<typename T>
class Box
{
public:
	Box( ) = default;
	Box( const T x, const T y, const T width, const T height )
	{
		auto centerPoint	= Point<T>( x + ( width / 2.0f ), y + ( height / 2.0f ) );
		auto halfWidth		= Point<T>( width / 2.0f, 0.0f );
		auto halfHeight		= Point<T>( 0.0f, height / 2.0f );

		localAABB = AABB<T>( centerPoint, halfWidth, halfHeight );
	}

	bool isColliding( const AABB<T>& AABB )
	{
		bool xOverlap = Abs( localAABB.centerPoint[0] - AABB.centerPoint[0] ) <= ( localAABB.halfWidth[0] + AABB.halfWidth[0] );
		bool yOverlap = Abs( localAABB.centerPoint[1] - AABB.centerPoint[1] ) <= ( localAABB.halfHeight[1] + AABB.halfHeight[1] );

		std::cout << "xOverlap: " << xOverlap << '\n';
		std::cout << "yOverlap: " << yOverlap << '\n';

		return xOverlap && yOverlap;
	}

	const AABB<T> GetAABB( ) const { return localAABB; }

private:
	double Abs( double a )
	{
		return std::fabs( a );
	}

private:
	AABB<T> localAABB;
};