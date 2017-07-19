/**
 *	@file	Sprite.h
 *	@author	BouwnLaw
 *	@date	09/07/2017
 *	@brief	Create a Sprite.
 *
 *	Create using Renderable.h as a base using a texture.
 */
#pragma once

// Include Deps
#include <glm/glm.hpp>

// Include Project
#include "Renderable.h"
#include "../texture/Texture.h"
#include "../shapes/Rect.h"

/**
 *	@brief	Create a Sprite.
 *
 *	Create using Renderable.h as a base using a texture.
 */
class Sprite : public Renderable
{
public:
	/**
	 *	@brief	Default constructor.
	 *
	 *	Default constructor.
	 */
	Sprite() = default;
	/**
	 *	@brief	Constructor.
	 *
	 *	Create a sprite using the texture's size.
	 *
	 *	@param	position, glm::vec3 position of the sprite
	 *	@param	pTexture, shared_ptr to the texture.
	 */
	Sprite( const glm::vec3& m_Position, std::shared_ptr<Texture> pTexture );
	/**
	 *	@brief	Constructor.
	 *
	 *	Create a sprite.
	 */
	Sprite( const glm::vec3& m_Position, const glm::vec2& m_Size, std::shared_ptr<Texture> pTexture );

	/**
	 *	@brief	Render the sprite.
	 *
	 *	Render the sprite.
	 */
	void Render( Shader& shader ) override;

	void AddTextureRect( float x, float y, float dx, float dy );

private:
	VertexBuffer m_TexCoordVBO;
	FloatRect m_TextureRect;

	std::shared_ptr<Texture> m_pTexture;
};