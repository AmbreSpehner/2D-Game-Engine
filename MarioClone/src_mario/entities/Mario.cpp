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

	if( isMovingLeft )
	{
		position.x -= 30 * deltaTime;
	}
	if( isMovingRight )
	{
		position.x += 30 * deltaTime;
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

void Mario::MoveLeft( )
{
	std::cout << "left\n";
	isMovingLeft = true;
}

void Mario::MoveRight( )
{
	isMovingRight = true;
}

void Mario::Jump( )
{
	isJumping = true;
}

void Mario::NotMovingLeft( )
{
	isMovingLeft = false;
}

void Mario::NotMovingRight( )
{
	isMovingRight = false;
}

void Mario::NotJumping( )
{
	isJumping = false;
}
