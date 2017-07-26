#include "SegmentShape.h"

SegmentShape::SegmentShape( const Position & p1, const Position & p2, const Colour& colour, unsigned short type = 1 )
	:
	Renderable( p1, p2, colour, type )
{
	std::vector<GLfloat> vertices =
	{
		p1.x, p1.y, p1.z
	};
}