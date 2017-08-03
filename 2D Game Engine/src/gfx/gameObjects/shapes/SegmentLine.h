#pragma once

#include "../Renderable.h"

class SegmentLine : public Renderable
{
public:
	SegmentLine( ) = default;
	SegmentLine( const GLf_Point& p1, const GLf_Point& p2, const Colour& colour, unsigned short type = 1 );

	void Render( Shader& shader );

	void SetLineWidth( float lineWidth );
	void SetColour( const Colour& colour );
	void SetPoint( const GLf_Point& p, int index );
	void SetPoints( const GLf_Point& p1, const GLf_Point& p2 );

	const float& GetLineWidth( ) const { return lineWidth; }
	const Colour& GetColour( ) const { return colour; }
	const GLf_Point& GetPoint( int index ) const
	{
		if( index == VertexNum::P1 )
			return p1;
		else if( index == VertexNum::P2 )
			return p2;
		else
			throw std::out_of_range{ "Chosen vertex does not exist!\n" };
	}

public:
	enum VertexNum
	{
		P1 = 0,
		P2 = 1
	};
};