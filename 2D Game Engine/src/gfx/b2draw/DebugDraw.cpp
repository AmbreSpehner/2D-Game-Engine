#include "DebugDraw.h"

#include "../gameObjects/shapes/SegmentLine.h"

void DebugDraw::DrawPolygon( const b2Vec2 * vertices, int32 vertexCount, const b2Color & colour )
{
	GLfloat glverts[16];
	glVertexPointer( 2, GL_FLOAT, 0, glverts );
	glEnableClientState( GL_VERTEX_ARRAY );

	for( int i = 0; i < vertexCount; i++ ) {
		glverts[i * 2] = vertices[i].x;
		glverts[i * 2 + 1] = vertices[i].y;
	}

	glLineWidth( 3 );
	glColor4f( 1, 0, 1, 1 );
	glDrawArrays( GL_LINE_LOOP, 0, vertexCount );
}

void DebugDraw::DrawSolidPolygon( const b2Vec2 * vertices, int32 vertexCount, const b2Color & colour )
{
	GLfloat glverts[16];
	glVertexPointer( 2, GL_FLOAT, 0, glverts );
	glEnableClientState( GL_VERTEX_ARRAY );

	for( int i = 0; i < vertexCount; i++ ) {
		glverts[i * 2] = vertices[i].x;
		glverts[i * 2 + 1] = vertices[i].y;
	}

	glColor4f( colour.r, colour.g, colour.b, 1 );
	glDrawArrays( GL_TRIANGLE_FAN, 0, vertexCount );

	glLineWidth( 3 );
	glColor4f( 1, 0, 1, 1 );
	glDrawArrays( GL_LINE_LOOP, 0, vertexCount );
}

void DebugDraw::DrawCircle( const b2Vec2 * center, float32 radius, const b2Color & colour )
{

}

void DebugDraw::DrawSolidCircle( const b2Vec2 * center, float radius, const b2Vec2 * axis, const b2Color & colour )
{

}

void DebugDraw::DrawSegment( const b2Vec2 * p1, const b2Vec2 * p2, const b2Color & colour )
{
	
}
