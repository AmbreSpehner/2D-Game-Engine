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
		static void MoveRight( )
		{
			
		}

		static void MoveLeft( )
		{

		}

		static void Jump( )
		{

		}
	};
};

static constexpr float SCALE = 3.0f;