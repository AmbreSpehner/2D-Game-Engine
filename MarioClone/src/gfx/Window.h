#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "structs/Colour.h"

class Window
{
public:
	Window( const GLint width, const GLint height, const std::string& title );
	~Window();

	void ProcessInput();

	void Update();
	void Clear( Colour& colour );

	bool IsClosed();

	void SetIcon( const std::string& path );
	void SetKeyCallback( GLFWkeyfun keyCallback );
	void SetMouseButtonCallback( GLFWmousebuttonfun mouseButtonCallback );
	void SetMousePositionCallback( GLFWcursorposfun mousePositionCallback );

	void EnableFrameLimit( bool state );

public:
	GLFWwindow* pWindow;

private:
	GLint width;
	GLint height;
	std::string title;
};