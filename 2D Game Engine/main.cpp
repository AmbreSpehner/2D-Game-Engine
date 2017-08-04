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
#include "src/gfx/gameObjects/RenderableImage.h"
#include "src/gfx/fonts/TrueTypeFont.h"
#include "src/collision/shapes/Box.h"

#include <Box2D/Box2D.h>

std::unordered_map<std::string, std::shared_ptr<Texture>> TextureCodex::pTextureMap;

int main( )
{
	Window window( 1000, 800, "OpenGL" );
	window.SetIcon( "res/wall.jpg" );
	window.EnableFrameLimit( false );

	TextureCodex::Discard( );

	Shader shader( "shaders/VertexShader.glsl", "shaders/FragmentShader.glsl" );
	VertexArray VAO;

	RectangleShape shape1( Position( 100, 100.0f ), GLf_Size( 100, 100 ), Colour( 0.0f, 0.0f, 0.0f, 1.0f ), Renderable::FILLED );
	TriangleShape shape2( Point<GLfloat>( 100.0f, 100.0f ), Point<GLfloat>( 200.0f, 100.0f ), Point<GLfloat>( 100.0f, 200.0f ), Colour( 0.0f, 1.0f, 0.0f, 1.0f ) );

	Box<GLfloat> box1( 0, 0, 100.0f, 100.0f );
	Box<GLfloat> box2( -101, -101, 100.0f, 100.0f );

	box1.isColliding( box2.GetAABB( ) );

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

		glm::mat4 view;
		glm::mat4 projection;
		view = glm::lookAt( glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 0.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
		projection = glm::ortho( 0.0f, 1000.0f, 0.0f, 800.0f, 0.1f, 100.0f );

		shader.SetUniformMat4f( "view", view );
		shader.SetUniformMat4f( "projection", projection );

		VAO.Bind( );

		shape2.Render( shader );
		shape1.Render( shader );

		VAO.Unbind( );

		shader.Disable( );
	}

	return 0;
}