#include "Animation.h"

#include <iostream>

Animation::Animation( float x, float y, float dx, float dy, int numFrames, float holdTime )
	:
	holdTime( holdTime )
{
	frames.reserve( numFrames );

	for( int i = 0; i < numFrames; i++ )
	{
		frames.emplace_back( x, y, dx, dy );
		x += dx;
	}
}

void Animation::ApplyToSprite( Sprite & sprite ) const
{
	sprite.SetTextureRect( frames[frameIndex].x, frames[frameIndex].y,
						   frames[frameIndex].dx, frames[frameIndex].dy );
}

void Animation::Update( float deltaTime )
{
	time += deltaTime;

	while( time >= holdTime )
	{
		time -= holdTime;
		Advance( );
	}
}

void Animation::Advance( )
{
	if( ++frameIndex >= int( frames.size( ) ) )
	{
		frameIndex = 0;
	}
}