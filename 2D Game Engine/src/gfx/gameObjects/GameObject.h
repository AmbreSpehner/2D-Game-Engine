#pragma once

#include <unordered_map>
#include <memory>

#include "Renderable.h"
#include "RectangleShape.h"
#include "Sprite.h"
#include "Texture.h"

class GameObject
{
public:
	class Factory
	{
	public:
		void SetSprite( const std::string& name, const glm::vec3& pos, std::shared_ptr<Texture> texture )
		{
			auto pSprite = std::make_unique<Sprite>( pos, texture );
			renderableMap[name] = std::move( pSprite );
		}

		void SetSprite( const std::string& name, const glm::vec3& pos, const glm::vec2& size, std::shared_ptr<Texture> texture )
		{
			renderableMap[name] = std::make_unique<Sprite>( pos, size, texture );
		}

		void SetRectangleShape( const std::string& name, const glm::vec3& pos, const glm::vec2& size, const glm::vec4& colour )
		{
			renderableMap[name] = std::make_unique<RectangleShape>( pos, size, colour );
		}

		GameObject CreateGameObject( const std::string& name )
		{
			auto iterator = renderableMap.find( name );

			if( iterator == renderableMap.end() )
			{
				throw std::exception{ "Unable to retrieve the renderable!" };
			}

			GameObject gameObject;
			gameObject.renderables = iterator->second.get();

			return gameObject;
		}

	public:
		std::unordered_map<std::string, std::unique_ptr<Renderable>> renderableMap;
	};

protected:
	Renderable* renderables;
};