#include "Game.h"

std::unordered_map<std::string, std::shared_ptr<Texture>> TextureCodex::pTextureMap;

Game::Game( )
	:
	tileset( TextureCodex::Acquire( "res/tileset.png" ) )
{
	mario = Mario( Position( 100.0f, 200.0f ) );
	groundBlock = GroundBlock( Position( 100.0, 100.0f ), tileset );

}

void Game::Update( float deltaTime )
{
	mario.Update( deltaTime );
	mario.HitGround( groundBlock );
}

void Game::Render( Shader & shader )
{
	groundBlock.Render( shader );

	mario.Render( shader );
}