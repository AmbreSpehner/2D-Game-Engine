#pragma once

#include "../Renderable.h"

class SegmentLine : public Renderable
{
public:
	SegmentLine( ) = default;
	SegmentLine( const Position& p1, const Position& p2, const Colour& colour, unsigned short type = 1 );

	void Render( Shader& shader );

	void SetLineWidth( float lineWidth );
	void SetColour( const Colour& colour );
	void SetPoint( const Position& p, int number );
	void SetPoints( const Position& p1, const Position& p2 );

	const float& GetLineWidth( ) const { return lineWidth; }
	const Colour& GetColour( ) const { return colour; }
	const Position& GetPoint( int number ) const
	{
		if( number == VertexNum::P1 )
			return p1;
		else if( number == VertexNum::P2 )
			return p2;
		else
			throw std::out_of_range{ "Chosen vertex does not exist!\n" };
	}

public:
	enum VertexNum
	{
		P1 = 1,
		P2 = 2
	};
};