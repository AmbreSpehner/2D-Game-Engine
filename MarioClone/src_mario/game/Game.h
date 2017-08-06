#pragma once

#include <array>

#include "../../src/gfx/texture/TextureCodex.h"
#include "../../src/shader/Shader.h"

#include "../blocks/GroundBlock.h"
#include "../entities/Mario.h"

class Game
{
public:
	Game( );

	void Update( float deltaTime );
	void Render( Shader& shader );

private:
	Mario mario;

	GroundBlock groundBlock;

	std::shared_ptr<Texture> tileset;

public:
	class InputManager
	{
	public:
		static void MoveRight( Game& game )
		{
			game.mario.MoveRight( );
		}

		static void MoveLeft( Game& game )
		{
			game.mario.MoveLeft( );
		}

		static void Jump( Game& game )
		{
			game.mario.Jump( );
		}

		static void NotMovingRight( Game& game )
		{
			game.mario.NotMovingRight( );
		}

		static void NotMovingLeft( Game& game )
		{
			game.mario.NotMovingLeft( );
		}

		static void NotJumping( Game& game )
		{
			game.mario.NotJumping( );
		}
	};
};

static constexpr float SCALE = 3.0f;