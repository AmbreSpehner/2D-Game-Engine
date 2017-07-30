#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "Texture.h"


class TextureCodex
{
public:
	static std::shared_ptr<Texture> Acquire( const std::string& filepath )
	{
		const auto i = pTextureMap.find( filepath );
		if( i != pTextureMap.end() )
		{
			return i->second;
		}
		else
		{
			auto pTexture = std::make_shared<Texture>( filepath );

			pTextureMap.insert( { filepath, pTexture } );

			return pTexture;
		}
	}

	static std::shared_ptr<Texture> Acquire( const GLchar name, std::vector<Texture::Pixel>& buffer, GLfloat width, GLfloat height )
	{
		const auto i = pTextureMap.find( { name } );
		if( i != pTextureMap.end( ) )
		{
			return i->second;
		}
		else
		{
			auto pTexture = std::make_shared<Texture>( buffer, width, height );

			pTextureMap.insert( { { name }, pTexture } );

			return pTexture;
		}
	}

	static void Discard()
	{
		for( auto i = pTextureMap.begin(); i != pTextureMap.end(); )
		{
			if( i->second.unique() )
			{
				i = pTextureMap.erase( i );
			}
			else
			{
				++i;
			}
		}
	}

private:
	static std::unordered_map<std::string, std::shared_ptr<Texture>> pTextureMap;
};