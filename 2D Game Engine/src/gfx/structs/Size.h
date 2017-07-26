#pragma once

struct Size
{
	Size( ) = default;
	Size( GLfloat xIn, GLfloat yIn )
	{
		x = xIn;
		y = yIn;
	}

	void Set( GLfloat xIn, GLfloat yIn )
	{
		x = xIn;
		y = yIn;
	}

	GLfloat x, y;
};