/**
 *	@file	TextureCodex.h
 *	@author	BouwnLaw
 *	@date	08/07/2017
 *	@brief	Holds all textures until deletion.
 *
 *	Hold all textures within an unordered map with shared pointers
 *	until the texture is deleted.
 */

#pragma once

// Include STL
#include <memory>
#include <string>
#include <unordered_map>

// Include Project
#include "../gameObjects/Texture.h"

/**
 *	@brief	Holds all textures until deletion.
 *
 *	Hold all textures within an unordered map with shared pointers
 *	until the texture is deleted.
 */
class TextureCodex
{
public:
	/**
	 *	@brief	Retrieve a texture and store it.
	 *
	 *	Retrieve a texture if it already exist in the unordered map, if
	 *	it does not already exist in the map, it creates a new pointer to
	 *	the texture in the map.
	 *
	 *	@param	name, Name of the texture to be retrieved
	 *
	 *	@return	std::shared_ptr, pointer to the texture
	 */
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

	/**
	 *	@brief Delete all texture within the map.
	 *
	 *	Destroy all textures within the unordered map if any.
	 */
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