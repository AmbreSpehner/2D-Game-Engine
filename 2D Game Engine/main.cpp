#include <cmath>
#include <vector>
#include <chrono>

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <irrklang/irrKlang.h>

#include "src/gfx/Window.h"
#include "src/gfx/buffers/VertexArray.h"
#include "src/gfx/buffers/VertexBuffer.h"
#include "src/gfx/buffers/IndexBuffer.h"
#include "src/gfx/gameObjects/shapes/RectangleShape.h"
#include "src/gfx/gameObjects/GameObject.h"
#include "src/gfx/gameObjects/Sprite.h"
#include "src/gfx/texture/Texture.h"
#include "src/gfx/texture/TextureCodex.h"
#include "src/gfx/Renderer2D.h"
#include "src/shader/Shader.h"
#include "src/utils/File_Reader.h"
#include "src/gfx/Animation/Animation.h"
#include "src/gfx/gameObjects/shapes/TriangleShape.h"
#include "src/gfx/gameObjects/shapes/SegmentLine.h"

#include <Box2D/Box2D.h>

std::unordered_map<std::string, std::shared_ptr<Texture>> TextureCodex::pTextureMap;

int main( )
{
	Window window( 1000, 800, "OpenGL" );
	window.SetIcon( "res/wall.jpg" );
	// window.EnableFrameLimit( true );

	TextureCodex::Discard( );

	Shader shader( "shaders/VertexShader.glsl", "shaders/FragmentShader.glsl" );
	VertexArray VAO;
	Renderer2D renderer;

	Sprite sprite( Position( 100.0f, 100.0f, 0.0f ), TextureCodex::Acquire( "res/paddle.png" ) );
	sprite.SetTextureRect( 0, 16, 32, 8 );
	sprite.ScaleSprite( 3.0f );

	Animation anim( 0.0f, 16.0f, 32.0f, 8.0f, 16, 0.5f );

	// TrueTypeFont ttf( "res/fonts/arial.ttf", 80 );

	auto timePoint = std::chrono::steady_clock::now( );

	while( !window.IsClosed( ) )
	{
		window.ProcessInput( );
		window.Update( );
		window.Clear( Colour( 0.0f, 0.0f, 0.0f, 1.0f ) );

		float deltaTime;
		{
			const auto newTimePoint = std::chrono::steady_clock::now( );
			deltaTime = std::chrono::duration<float>( newTimePoint - timePoint ).count( );
			timePoint = newTimePoint;
		}

		shader.Enable( );

		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		view = glm::lookAt( glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 0.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
		projection = glm::ortho( 0.0f, 1000.0f, 0.0f, 800.0f, 0.1f, 100.0f );

		shader.SetUniformMat4f( "model", model );
		shader.SetUniformMat4f( "view", view );
		shader.SetUniformMat4f( "projection", projection );

		anim.Update( deltaTime );
		anim.ApplyToSprite( sprite );

		VAO.Bind( );

		ttf.RenderText( shader, "Hello", 500.0f, 500.0f, 1.0f, Colour( 1.0f, 0.0f, 0.0f, 1.0f ) );
		sprite.Render( shader );

		VAO.Unbind( );

		shader.Disable( );
	}

	return 0;
}