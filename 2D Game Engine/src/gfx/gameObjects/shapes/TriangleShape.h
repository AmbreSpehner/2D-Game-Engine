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
	TriangleShape( const Position& p1, const Position& p2, const Position& p3, const Colour& colour, unsigned short type = 0 );

	void Render( Shader& shader ) override;

	void SetVertex( const Position& vertex, int number );
	void SetVertices( const Position& p1, const Position& p2, const Position& p3 );
	void SetColour( const Colour& colour );

	const Position& GetVertex( int number ) const;
	const Colour& GetColour( ) const { return colour; }

public:
	enum VertexNum
	{
		P1 = 1,
		P2 = 2,
		P3 = 3
	};
};