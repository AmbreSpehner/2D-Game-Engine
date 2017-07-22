#include "Animation.h"

#include <iostream>

Animation::Animation( float x, float y, float dx, float dy, int numFrames, float holdTime )
	:
	m_HoldTime( holdTime )
{
	m_Frames.reserve( numFrames );

	for( int i = 0; i < numFrames; i++ )
	{
		m_Frames.emplace_back( x, y, dx, dy );
		x += dx;
	}
}

void Animation::ApplyToSprite( Sprite & sprite ) const
{
	sprite.SetTextureRect( m_Frames[m_FrameIndex].x, m_Frames[m_FrameIndex].y,
						   m_Frames[m_FrameIndex].dx, m_Frames[m_FrameIndex].dy );
}

void Animation::Update( float deltaTime )
{
	m_Time += deltaTime;

	while( m_Time >= m_HoldTime )
	{
		m_Time -= m_HoldTime;
		Advance( );
	}
}

void Animation::Advance( )
{
	if( ++m_FrameIndex >= int( m_Frames.size( ) ) )
	{
		m_FrameIndex = 0;
	}
}