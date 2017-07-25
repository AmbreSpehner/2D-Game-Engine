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
	TriangleShape( const Position& vertPos1, const Position& vertPos2, const Position& vertPos3, const Colour& colour );

	void Render( Shader& shader ) override;

	void SetVertex( const Position& vertex, int number );
	void SetVertices( const Position& vertPos1, const Position& vertPos2, const Position& vertPos3 );
	void SetColour( const Colour& colour );

	const Position& GetVertex( int number ) const;
	const Colour& GetColour( ) const;

public:
	enum VertexNum
	{
		VERT_1 = 1,
		VERT_2 = 2,
		VERT_3 = 3
	};
};