#pragma once

#include <memory>

#include "../../src/gfx/structs/Structs.h"
#include "../../src/gfx/texture/Texture.h"
#include "../../src/gfx/gameObjects/Sprite.h"
#include "../../src/collision/shapes/Box.h"

class GroundBlock
{
public:
	GroundBlock( ) = default;
	GroundBlock( const Position& position, std::shared_ptr<Texture> pTexture );

	void Update( );
	void Render( Shader& shader );

	const Position& GetPosition( ) const { return position; }
	const GLf_Size& GetSize( ) const { return sprite.GetSize( ); }

	const Box<float> GetCollisionBox( ) const { return collisionBox; }

private:
	Position position;

	Sprite sprite;

	Box<float> collisionBox;
};