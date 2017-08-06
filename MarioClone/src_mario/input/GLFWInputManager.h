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
			if( key == GLFW_KEY_A )	MoveLeft( game );
			if( key == GLFW_KEY_D ) MoveRight( game );
		}

		if( action == GLFW_PRESS )
		{
			if( key == GLFW_KEY_SPACE )	Jump( game );
		}

		if( action == GLFW_RELEASE )
		{
			if( key == GLFW_KEY_A ) NotMovingLeft( game );
			if( key == GLFW_KEY_D ) NotMovingRight( game );
			if( key == GLFW_KEY_SPACE )NotJumping( game );
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