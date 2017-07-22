#include "Renderer2D.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

void Renderer2D::Submit( Renderable* renderable )
{
	m_RenderQueue.push_back( renderable );
}

void Renderer2D::Flush( VertexArray& VAO, Shader& shader )
{
	while ( !m_RenderQueue.empty() )
	{
		Renderable* renderable = m_RenderQueue.front();

		glm::mat4 model;
		model = glm::translate( model, renderable->GetRectPosition() );

		shader.SetUniformMat4f( "model", model );

		renderable->Render( shader );

		m_RenderQueue.pop_front();
	}
}