#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../buffers/VertexBuffer.h"
#include "../buffers/VertexArray.h"

#include "Renderable.h"

class TriangleShape : public Renderable
{
public:
	TriangleShape( ) = default;
	TriangleShape( const glm::vec3& vertPos1, const glm::vec3& vertPos2, const glm::vec3& vertPos3, const glm::vec4& colour );
	TriangleShape( const glm::vec3& vertPos1, const glm::vec3& vertPos2, const glm::vec3& vertPos3, const glm::vec4& colour, int type );

	void Render( Shader& shader );

private:
};