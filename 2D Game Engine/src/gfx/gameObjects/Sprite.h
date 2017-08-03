#pragma once

#include <glm/glm.hpp>

#include "Renderable.h"
#include "../texture/Texture.h"
#include "../../collision/shapes/Rect.h"

class Sprite : public Renderable
{
public:
	Sprite() = default;
	Sprite( const Position& position, std::shared_ptr<Texture> pTexture );
	Sprite( const Position& position, const GLf_Size& size, std::shared_ptr<Texture> pTexture );

	void Render( Shader& shader ) override;

	void SetPosition( Position& position );
	void SetSize( GLf_Size& size );

	const Position& GetPosition( ) const { return position; }
	const GLf_Size& GetSize( ) const { return size; }

	void SetScale( float scale );
	void SetTexture( std::shared_ptr<Texture> pTexture );
	void SetTextureRect( const FloatRect& rect );
	void SetTextCoords( const float x, const float y, const float dx, const float dy );

	Sprite& operator=( Sprite&& rSprite ) = default;

private:
	float scale;

	FloatRect textureRect;

	std::shared_ptr<Texture> pTexture;
};