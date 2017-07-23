#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../../buffers/VertexBuffer.h"
#include "../../buffers/VertexArray.h"

#include "../Renderable.h"

class TriangleShape : public Renderable
{
public:
	TriangleShape( ) = default;
	TriangleShape( const glm::vec3& vertPos1, const glm::vec3& vertPos2, const glm::vec3& vertPos3, const glm::vec4& colour );
	TriangleShape( const glm::vec3& vertPos1, const glm::vec3& vertPos2, const glm::vec3& vertPos3, const glm::vec4& colour, int type );

	void Render( Shader& shader ) override;

	void SetVertex( const glm::vec3& vertex, int number );
	void SetVertices( const glm::vec3& vertPos1, const glm::vec3& vertPos2, const glm::vec3& vertPos3 );
	void SetColour( const glm::vec4& colour );

	const glm::vec3& GetVertex( int number ) const;
	const glm::vec4& GetColour( ) const;

public:
	enum VertexNum
	{
		VERT_1 = 0,
		VERT_2 = 1,
		VERT_3 = 2
	};
};