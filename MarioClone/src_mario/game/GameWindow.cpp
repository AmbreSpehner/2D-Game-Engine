#include "GameWindow.h"

#include <chrono>
#include <algorithm>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../src/gfx/structs/Colour.h"

#include "../input/GLFWInputManager.h"

GameWindow::GameWindow( const int width, const int height, const std::string& title )
	:
	Window( width, height, title ),
	width( width ),
	height( height ),
	title( title ),
	shader( "shaders/VertexShader.glsl", "shaders/FragmentShader.glsl" )
{
	Window::EnableFrameLimit( false );
	Window::SetKeyCallback( GLFWInputManager::KeyCallback );
	Window::SetMouseButtonCallback( GLFWInputManager::MouseButtonCallback );
	Window::SetMousePositionCallback( GLFWInputManager::MousePositionCallback );

	glfwSetWindowUserPointer( Window::pWindow, &game );
}

void GameWindow::MainLoop( )
{
	auto timePoint = std::chrono::steady_clock::now( );

	float maxDeltaTime = 1.0f / 20.0f;

	while( !Window::IsClosed( ) )
	{
		float deltaTime;
		{
			const auto newTimePoint = std::chrono::steady_clock::now( );
			deltaTime = std::chrono::duration<float>( newTimePoint - timePoint ).count( );
			timePoint = newTimePoint;
		}
		deltaTime = std::min( deltaTime, maxDeltaTime );

		Window::ProcessInput( );

		Update( deltaTime );
		Render( );
	}
}

void GameWindow::Update( float deltaTime )
{
	Window::Update( );

	view = glm::lookAt( glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 0.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
	projection = glm::ortho( 0.0f, 768.0f, 0.0f, 576.0f, 0.1f, 100.0f );

	game.Update( deltaTime );
}

void GameWindow::Render( )
{
	Window::Clear( Colour( 0.41961f, 0.54902f, 1.0f, 1.0f ) );

	shader.Enable( );
	shader.SetUniformMat4f( "view", view );
	shader.SetUniformMat4f( "projection", projection );

	VAO.Bind( );

	game.Render( shader );

	VAO.Unbind( );

	shader.Disable( );
}