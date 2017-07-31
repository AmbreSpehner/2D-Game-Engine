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
	TriangleShape( const GLf_Pos& p1, const GLf_Pos& p2, const GLf_Pos& p3, const GLf_Colour& colour, unsigned short type = 0 );

	void Render( Shader& shader ) override;

	void SetVertex( const GLf_Pos& vertex, int index );
	void SetVertices( const GLf_Pos& p1, const GLf_Pos& p2, const GLf_Pos& p3 );
	void SetColour( const GLf_Colour& colour );

	const GLf_Pos& GetVertex( int number ) const;
	const GLf_Colour& GetColour( ) const { return colour; }

public:
	enum VertexNum
	{
		P1 = 1,
		P2 = 2,
		P3 = 3
	};
};