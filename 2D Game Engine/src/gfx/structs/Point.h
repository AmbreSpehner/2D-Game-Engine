#pragma once

#include "Position.h"

template<typename T>
struct Point
{
	Point( ) : x( 0 ), y( 0 ), z( 0 ) {	}
	Point( T x, T y, T z = 0.0 ) : x( x ), y( y ), z( z ) {	}
	Point( const Position& p ) : x( p.x ), y( p.y ), z( p.z ) {	}

	explicit operator glm::vec3( ) { return glm::vec3( x, y, z ); }
	const T operator[]( const int index ) const
	{
		if( index == 0 ) return x;
		if( index == 1 ) return y;
		if( index == 2 ) return z;
	}

	T x, y, z;
};