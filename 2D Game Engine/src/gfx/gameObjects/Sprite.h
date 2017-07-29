#pragma once

#include <glm/glm.hpp>

#include "Renderable.h"
#include "../texture/Texture.h"
#include "../shapes/Rect.h"

class Sprite : public Renderable
{
public:
	Sprite() = default;
	Sprite( const Position& position, std::shared_ptr<Texture> pTexture );
	Sprite( const Position& position, const GLf_Size& size, std::shared_ptr<Texture> pTexture );

	void Render( Shader& shader ) override;

	void SetPosition( Position& position );
	void SetSize( GLf_Size& size );
	void SetColour( Colour& colour );

	const Position& GetPosition( ) const { return position; }
	const GLf_Size& GetSize( ) const { return size; }
	const Colour& GetColour( ) const { return colour; }

	void SetTexture( std::shared_ptr<Texture> pTexture );

	void ScaleSprite( float scale );
	
	void SetTextureRect( const FloatRect& rect );
	void SetTextureRect( const float x, const float y, const float dx, const float dy );
	void SetTextureRect( const Position& position, const GLf_Size& size );

	void SetTextCoords( const float x, const float y, const float dx, const float dy );
	void SetTextCoords( const Position& position, const GLf_Size& size );

	Sprite& operator=( Sprite&& rSprite ) = default;

private:
	float scale;

	FloatRect textureRect;

	std::shared_ptr<Texture> pTexture;
};