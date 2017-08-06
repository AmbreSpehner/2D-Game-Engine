#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../game/Game.h"

class GLFWInputManager : private Game::InputManager
{
public:
	static void KeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode )
	{
		Game& game = *reinterpret_cast< Game* >( glfwGetWindowUserPointer( window ) );

		if( action == GLFW_PRESS || action == GLFW_REPEAT )
		{
			MoveRight( );
			MoveLeft( );
		}

		if( action == GLFW_PRESS )
		{
			Jump( );
		}

		if( action == GLFW_RELEASE )
		{

		}
	}

	static void MouseButtonCallback( GLFWwindow* window, int button, int action, int mode )
	{
		Game& game = *reinterpret_cast< Game* >( glfwGetWindowUserPointer( window ) );

		if( action == GLFW_PRESS )
		{
			
		}

		if( action == GLFW_RELEASE )
		{

		}
	}

	static void MousePositionCallback( GLFWwindow* window, double xPos, double yPos )
	{
		Game& game = *reinterpret_cast< Game* >( glfwGetWindowUserPointer( window ) );

		glfwGetCursorPos( window, &xPos, &yPos );
	}
};