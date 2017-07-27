#pragma once

#include <deque>
#include <memory>

#include "gameObjects/shapes/RectangleShape.h"

#include "../shader/Shader.h"

class Renderer2D
{
public:
	void Submit( Renderable* shape );
	void Flush( VertexArray& VAO, Shader& shader );

private:
	std::deque<Renderable*> renderQueue;
};