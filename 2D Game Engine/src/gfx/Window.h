/**
 *	@file		Window.h
 *	@Author		BouwnLaw
 *	@date		07/07/2017
 *  @brief		Creates a GLFW window instance.
 *
 *	Create a GLFW window instance.
 */

#pragma once

// Include STL
#include <string>

// Include Deps
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/**
 *	@brief	Create a GLFW window instance and initialize GLEW.
 *
 *	Create and set up a GLFW window and initialize GLEW to create
 *	a window capable of reading input and rendering.
 */
class Window
{
public:
	/**
	 *	@brief	Constructor.
	 *
	 *	Set up a GLFW window context and initialize GLEW.
	 *
	 *	@param	width, Width of the window
	 *	@param	height, Height of the window
	 *	@param	title of the window
	 */
	Window( const GLint width, const GLint height, const std::string& title );

	/**
	 *	@brief	Destructor.
	 *
	 *	Destroy the GLFW window.
	 */
	~Window();

	/**
	 *	@brief	Check for events.
	 *
	 *	Check for events.
	 */
	void ProcessInput();
	/**
	 *	@brief	Update the window.
	 *
	 *	Update the window.
	 */
	void Update();
	/**
	 *	@brief	Clear the window.
	 *
	 *	Clear the window.
	 */
	void Clear();

	/**
	 *	@brief	Check if the window is closed.
	 *
	 *	Check if the window is closed.
	 *
	 *	@return boolean result
	 */
	bool IsClosed();

	/**
	 *	@brief	Give the window an Icon.
	 *
	 *	Give the window an Icon.
	 *
	 *	@param	path, const std::string&
	 */
	void SetIcon( const std::string& path );

	/**
	 *	@brief Set a KeyCallback.
	 *
	 *	Set a KeyCallback to process input.
	 *
	 *	@param	keyCallback, GLFWkeyfun
	 */
	void SetKeyCallback( GLFWkeyfun keyCallback );

public:
	GLFWwindow* m_pWindow;

private:
	GLint m_Width;
	GLint m_Height;
	std::string m_Title;
};