#pragma once

#include "../texture/TextureCodex.h"
#include "../gameObjects/Sprite.h"
#include "../../collision/shapes/Rect.h"

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
	float holdTime;
	float time = 0.0f;
	int frameIndex = 0;

	std::vector<FloatRect> frames;
};