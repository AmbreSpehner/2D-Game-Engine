#pragma once

#include <stdexcept>

#include "../../gfx/structs/Structs.h"

template<typename T>
struct Line
{
	Line( ) = default;
	Line( const Point<T>& p1, const Point<T>& p2 )
		: p1( p1 ), p2( p2 ) {	}

	void SetLine( const Point<T>& p1, const Point<T>& p2 )
	{
		this->p1 = p1;
		this->p2 = p2;
	}

	void SetVertex( const Point<T>& vertex, int index )
	{
		if( index == P1 )
			this->p1 = vertex;
		else if( index == p2 )
			this->p2 = vertex;
		else
			throw std::out_of_range{ "The specified index does not exist!\n" };
	}

	const void GetVertex( int index ) const
	{
		if( index == P1 )
			return this->p1;
		else if( index == P2 )
			return this->p2;
		else
			throw std::out_of_range{ "The specified index does ot exist!\n" };
	}

	enum VertexIndex
	{
		P1 = 0,
		P2 = 1
	};

	Point<T> p1, p2;
};