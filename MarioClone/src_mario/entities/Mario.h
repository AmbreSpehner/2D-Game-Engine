#pragma once

#include <memory>
#include <array>

#include "../../src/gfx/gameObjects/Sprite.h"
#include "../../src/gfx/texture/Texture.h"
#include "../../src/gfx/structs/Position.h"
#include "../../src/shader/Shader.h"
#include "../../src/collision/shapes/Box.h"

#include "../blocks/GroundBlock.h"

class Mario
{
public:
	Mario( ) = default;
	Mario( const Position& position );

	void Update( float deltaTime );
	void Render( Shader& shader );

	void HitGround( GroundBlock& block );

	void MoveLeft( );
	void MoveRight( );
	void Jump( );

	void NotMovingLeft( );
	void NotMovingRight( );
	void NotJumping( );

private:
	Position position;

	Sprite sprite;

	std::shared_ptr<Texture> pTexture;

	Box<float> collisionBox;
	bool isHittingGround;

	float fallSpeed = 40.0f;
	float fallRate = 1.25f;

	bool isMovingLeft;
	bool isMovingRight;
	bool isJumping;
};