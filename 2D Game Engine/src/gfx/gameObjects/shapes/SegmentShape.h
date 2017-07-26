#pragma once

#include "../Renderable.h"

class SegmentShape : public Renderable
{
public:
	SegmentShape( ) = default;
	SegmentShape( const Position& p1, const Position& p2, const Colour& colour, unsigned short type = 1 );

};