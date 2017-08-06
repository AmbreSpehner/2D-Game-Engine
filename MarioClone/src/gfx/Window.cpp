#include "Window.h"

#include <stdexcept>

#include <SOIL/SOIL.h>

Window::Window( const GLint width, const GLint height, const std::string& title )
	:
	width( width ),
	height( height ),
	title( title )
{
	glfwInit();
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
	glfwWindowHint( GLFW_RESIZABLE, 0 );

	pWindow = glfwCreateWindow( this->width, this->height, this->title.c_str(), nullptr, nullptr );

	if( pWindow == nullptr )
	{
		throw std::runtime_error{ "Failed to initialize GLFW!\n" };
		glfwTerminate();
	}

	glfwMakeContextCurrent( pWindow );
	glfwSetWindowPos( pWindow, 100, 100 );

	glewExperimental = 1;
	if( glewInit() != 0 )
	{
		throw std::runtime_error{ "Failed to initialize GLEW!\n" };
	}

	glEnable( GL_DEPTH_TEST );

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	glViewport( 0, 0, this->width, this->height );
}

Window::~Window()
{
	glfwTerminate();
}

void Window::ProcessInput()
{
	glfwPollEvents();
}

void Window::Update()
{
	glfwSwapBuffers( pWindow );
}

void Window::Clear( Colour& colour )
{
	glClearColor( colour.r, colour.g, colour.b, colour.a );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

bool Window::IsClosed()
{
	return glfwWindowShouldClose( pWindow );
}

void Window::SetIcon( const std::string & path )
{
	GLFWimage icon;
	icon.pixels = SOIL_load_image( path.c_str(), &icon.width, &icon.height, 0, SOIL_LOAD_RGBA );

	glfwSetWindowIcon( pWindow, 1, &icon );
}

void Window::EnableFrameLimit( bool state )
{
	if( state == true )
	{
		glfwSwapInterval( 1 );
	}
}

void Window::SetKeyCallback( GLFWkeyfun keyCallback )
{
	glfwSetKeyCallback( pWindow, keyCallback );
}

void Window::SetMouseButtonCallback( GLFWmousebuttonfun mouseButtonCallback )
{
	glfwSetMouseButtonCallback( pWindow, mouseButtonCallback );
}

void Window::SetMousePositionCallback( GLFWcursorposfun mousePositionCallback )
{
	glfwSetCursorPosCallback( pWindow, mousePositionCallback );
}