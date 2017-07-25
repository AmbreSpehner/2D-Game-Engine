#pragma once

#include "../texture/TextureCodex.h"
#include "../gameObjects/Sprite.h"
#include "../shapes/Rect.h"

class Animation
{
public:
	Animation( ) = default;
	Animation( float x, float y, float dx, float dy, int numFrames, float holdTime );

	void ApplyToSprite( Sprite& sprite ) const;
	void Update( float deltaTime );

private:
	void Advance( );

private:
	float m_HoldTime;
	float m_Time = 0.0f;
	int m_FrameIndex = 0;

	std::shared_ptr<Texture> m_pTexture;
	std::vector<FloatRect> m_Frames;
};