#include "GroundBlock.h"

GroundBlock::GroundBlock( const Position& position, std::shared_ptr<Texture> pTexture )
	:
	sprite( position , pTexture ),
	position( position )
{
	sprite.SetScale( 3 );
	sprite.SetTextureRect( 0, 432, 16, 16 );

	collisionBox = Box<float>( this->position.x, this->position.y, sprite.GetSize( ).x, sprite.GetSize( ).y );
}

void GroundBlock::Update( )
{
	std::cout << position.y + sprite.GetSize( ).y << '\n';
}

void GroundBlock::Render( Shader& shader )
{
	sprite.Render( shader );
}
