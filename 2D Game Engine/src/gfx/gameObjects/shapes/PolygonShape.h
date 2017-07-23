#pragma once

#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Renderable.h"

#include "../../buffers/VertexBuffer.h"
#include "../../buffers/IndexBuffer.h"
#include "../../buffers/VertexArray.h"

class PolygonShape : public Renderable
{
public:
	PolygonShape( ) = default;
	PolygonShape( std::vector<glm::vec3>& vertPos, glm::vec4& colour );
	PolygonShape( std::vector<glm::vec3>& vertPos, glm::vec4& colour, int type );

	void Render( Shader& shader ) override;

private:
	enum ShaderLocation
	{
		POSITION = 0,
		COLOUR = 1,
		TEXTURE_COORD = 2
	};
};