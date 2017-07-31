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

public:
	enum VertexIndex
	{
		P1 = 0,
		P2 = 1
	};

private:
	Position<T> p1, p2;
};
