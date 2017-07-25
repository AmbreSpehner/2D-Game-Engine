#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window( const GLint width, const GLint height, const std::string& title );
	~Window();

	void ProcessInput();

	void Update();
	void Clear();

	bool IsClosed();

	void SetIcon( const std::string& path );
	void SetKeyCallback( GLFWkeyfun keyCallback );

	void EnableFrameLimit( bool state );

public:
	GLFWwindow* m_pWindow;

private:
	GLint m_Width;
	GLint m_Height;
	std::string m_Title;
};