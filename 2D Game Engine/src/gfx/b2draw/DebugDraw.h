#pragma once

#include <Box2D/Box2D.h>

class DebugDraw : public b2Draw
{
public:
	void DrawPolygon( const b2Vec2* vertices, int32 vertexCount, const b2Color& colour );
	void DrawSolidPolygon( const b2Vec2* vertices, int32 vertexCount, const b2Color& colour );
	void DrawCircle( const b2Vec2* center, float32 radius, const b2Color& colour );
	void DrawSolidCircle( const b2Vec2* center, float radius, const b2Vec2* axis, const b2Color& colour );
	void DrawSegment( const b2Vec2* p1, const b2Vec2* p2, const b2Color& colour );
};