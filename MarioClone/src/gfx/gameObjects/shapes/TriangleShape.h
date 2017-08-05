#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../../buffers/VertexBuffer.h"
#include "../../buffers/VertexArray.h"

#include "../Renderable.h"

class TriangleShape : public Renderable
{
public:
	TriangleShape( ) = default;
	TriangleShape( const Point<GLfloat>& p1, const Point<GLfloat>& p2, const Point<GLfloat>& p3, const Colour& colour, unsigned short type = 0 );

	void Render( Shader& shader ) override;

	void SetVertex( const Point<GLfloat>& vertex, int index );
	void SetVertices( const Point<GLfloat>& p1, const Point<GLfloat>& p2, const Point<GLfloat>& p3 );
	void SetColour( const Colour& colour );

	const Point<GLfloat>& GetVertex( int number ) const;
	const Colour& GetColour( ) const { return colour; }

public:
	enum VertexNum
	{
		P1 = 1,
		P2 = 2,
		P3 = 3
	};
};