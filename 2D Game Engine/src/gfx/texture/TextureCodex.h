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
		const auto i = m_pTextureMap.find( filepath );
		if( i != m_pTextureMap.end() )
		{
			return i->second;
		}
		else
		{
			auto pTexture = std::make_shared<Texture>( filepath );

			m_pTextureMap.insert( { filepath, pTexture } );

			return pTexture;
		}
	}

	static void Discard()
	{
		for( auto i = m_pTextureMap.begin(); i != m_pTextureMap.end(); )
		{
			if( i->second.unique() )
			{
				i = m_pTextureMap.erase( i );
			}
			else
			{
				++i;
			}
		}
	}

private:
	static std::unordered_map<std::string, std::shared_ptr<Texture>> m_pTextureMap;
};