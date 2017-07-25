#pragma once

struct Size
{
	Size( ) = default;
	Size( float xIn, float yIn )
	{
		x = xIn;
		y = yIn;
	}

	void Set( float xIn, float yIn )
	{
		x = xIn;
		y = yIn;
	}

	float x, y;
};