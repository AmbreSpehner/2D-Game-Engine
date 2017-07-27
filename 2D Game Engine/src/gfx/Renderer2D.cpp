#include "Renderer2D.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

void Renderer2D::Submit( Renderable* renderable )
{
	renderQueue.push_back( renderable );
}

void Renderer2D::Flush( VertexArray& VAO, Shader& shader )
{
	while ( !renderQueue.empty() )
	{
		Renderable* renderable = renderQueue.front();

		glm::mat4 model;
		model = glm::translate( model, renderable->GetPosition() );

		shader.SetUniformMat4f( "model", model );

		renderable->Render( shader );

		renderQueue.pop_front();
	}
}