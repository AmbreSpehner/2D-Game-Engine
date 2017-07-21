#include "Animation.h"
/*
Animation::Animation( int x, int y, int dx, int dy, int numFrames, float holdTime )
	:
	m_HoldTime( holdTime )
{
	m_Frames.reserve( numFrames );

	for( int i = 0; i < numFrames; i++ )
	{
		m_Frames.emplace_back( glm::vec2{ x, y }, glm::vec2{ dx, dy } );
		x += dx;
	}
}

void Animation::ApplyToSprite( Sprite & sprite ) const
{
	sprite.SetTextureRect( m_Frames[m_FrameIndex] );
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
*/
