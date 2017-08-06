#pragma once

#include <glm/glm.hpp>

#include "../../src/gfx/Window.h"
#include "../../src/gfx/buffers/VertexArray.h"

#include "Game.h"

class GameWindow : public Window
{
public:
	GameWindow( const int width, const int height, const std::string& title );

	void MainLoop( );

private:
	void Update( float deltaTime );
	void Render( );

public:

private:
	int width;
	int height;
	std::string title;

	glm::mat4 view;
	glm::mat4 projection;

	Game game;

	Shader shader;

	VertexArray VAO;
};