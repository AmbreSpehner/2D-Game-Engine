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

	/**
	 *	@brief	Set the texture of the sprite.
	 *
	 *	Set the texture of the sprite.
	 *
	 *	@param	pTexture, shared_ptr to the texture
	 */
	void SetTexture( std::shared_ptr<Texture> pTexture );

	/**
	 *	@brief	Scale the size of the sprite.
	 *
	 *	Scale the size of the sprite.
	 *
	 *	@param	scale, float to change the scale of the image
	 */
	void ScaleSprite( float scale );
	
	/**
	 *	@brief	Set the part of the texture the sprite uses.
	 *
	 *	Set the part of the texture the sprite uses.
	 *
	 *	@param	rect, the rectangle that define the part to be used
	 */
	void SetTextureRect( const FloatRect& rect );
	/**
	 *	@brief	Set the part of the texture the sprite uses.
	 *
	 *	Set the part of the texture the sprite uses.
	 *
	 *	@param	x, x position of the rectangle
	 *	@param	y, y position of the rectangle
	 *	@param	dx, width of the rectangle
	 *	@param	dy, height of the rectangle
	 */
	void SetTextureRect( const float x, const float y, const float dx, const float dy );
	/**
	 *	@brief	Set the part of the texture the sprite uses.
	 *
	 *	Set the part of the texture the sprite uses.
	 *
	 *	@param	position, position of the rectangle
	 *	@param	size, size of the rectangle
	 */
	void SetTextureRect( const glm::vec3& position, const glm::vec2& size );

	/**
	 *	@brief	Set the texture coordinates and the according buffers.
	 *
	 *	Set the texture coordinates and the according buffers to draw
	 *	the desired part of the image.
	 *
	 *	@param	x, position x of the coordinates
	 *	@param	y, position y of the coordinates
	 *	@param	dx, width of the texture
	 *	@param	dy, height of the texture
	 */
	void SetTextCoords( const float x, const float y, const float dx, const float dy );
	/**
	 *	@brief	Set the texture coordinates and the according buffers.
	 *
	 *	Set the texture coordinates and the according buffers to draw
	 *	the desired part of the image.
	 *
	 *	@param	position, position of the coordinates
	 *	@param	size, size of the coordinates
	 */
	void SetTextCoords( const glm::vec3& position, const glm::vec2& size );

	/**
	 *	@brief	default move operator.
	 *
	 *	Default move operator.
	 *
	 *	@param	rSprite, rValue sprite
	 */
	Sprite& operator=( Sprite&& rSprite ) = default;

private:
	float m_Scale;

	VertexBuffer m_TexCoordVBO;
	FloatRect m_TextureRect;

	std::shared_ptr<Texture> m_pTexture;
};