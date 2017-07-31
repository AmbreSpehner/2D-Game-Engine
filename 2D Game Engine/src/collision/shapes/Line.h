#pragma once

#include <stdexcept>

#include "../../gfx/structs/Structs.h"

template<typename T>
class Line
{
public:
	Line( ) = default;
	Line( const Position<T>& p1, const Position<T>& p2 )
		: p1( p1 ), p2( p2 ) {	}

	void SetLine( const Position<T>& p1, const Position<T>& p2 )
	{
		this->p1 = p1;
		this->p2 = p2;
	}

	void SetVertex( const Position<T>& vertex, int index )
	{
		if( int index == P1 )
			this->p1 = vertex;
		else if( int index == p2 )
			this->p2 = vertex;
		else
			throw std::out_of_range{ "The specified index does not exist!\n" };
	}

public:
	enum VertexIndex
	{
		P1 = 0,
		P2 = 1
	};

private:
	Position<T> p1, p2;
};
