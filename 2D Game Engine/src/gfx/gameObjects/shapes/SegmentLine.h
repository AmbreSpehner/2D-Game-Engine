#pragma once

#include "../Renderable.h"

class SegmentLine : public Renderable
{
public:
	SegmentLine( ) = default;
	SegmentLine( const GLf_Pos& p1, const GLf_Pos& p2, const GLf_Colour& colour, unsigned short type = 1 );

	void Render( Shader& shader );

	void SetLineWidth( float lineWidth );
	void SetColour( const GLf_Colour& colour );
	void SetPoint( const GLf_Pos& p, int index );
	void SetPoints( const GLf_Pos& p1, const GLf_Pos& p2 );

	const float& GetLineWidth( ) const { return lineWidth; }
	const GLf_Colour& GetColour( ) const { return colour; }
	const GLf_Pos& GetPoint( int index ) const
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