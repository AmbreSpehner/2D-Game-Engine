#include "Mario.h"

#include "../../src/gfx/texture/TextureCodex.h"

Mario::Mario( const Position & position )
	:
	position( position ),
	sprite( this->position, TextureCodex::Acquire( "res/marioset.png" ) ),
	isMovingLeft( false ),
	isMovingRight( false ),
	isJumping( false )
{
	sprite.SetScale( 3 );
	sprite.SetTextureRect( 0.0f, 0.0f, 16.0f, 16.0f );

	collisionBox = Box<float>( position.x, position.y, sprite.GetSize( ).x, sprite.GetSize( ).y );
}

void Mario::Update( float deltaTime )
{
	collisionBox.Set( position.x, position.y, sprite.GetSize( ).x, sprite.GetSize( ).y );
	sprite.SetPosition( position );

	if( isHittingGround == false )
	{
		position.y -= fallSpeed * deltaTime;
	}
}

void Mario::Render( Shader & shader )
{
	sprite.Render( shader );
}

void Mario::HitGround( GroundBlock & block )
{
	isHittingGround = collisionBox.isColliding( block.GetCollisionBox( ).GetAABB() );
}