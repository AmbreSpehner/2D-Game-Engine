#pragma once

#include "Renderable.h"
#include "../texture/Texture.h"
#include "../../collision/shapes/Rect.h"

class RenderableImage : public Renderable
{
public:
	RenderableImage( );
	RenderableImage( const Position& position, const GLf_Size& size, const Colour& colour, std::shared_ptr<Texture> pTexture, unsigned short type = 0.0f );

	void Render( Shader& shader );

	void SetPosition( const Position& position );
	void SetSize( const GLf_Size& size );
	void SetColour( const Colour& colour );
	void SetTextureRect( const FloatRect& rect );
	void SetTexture( const std::shared_ptr<Texture> pTexture );

	const Position& GetPosition( ) const { return position; }
	const GLf_Size& GetSize( ) const { return size; }
	const Colour& GetColour( ) const { return colour; }
	const FloatRect& GetRect( ) const { return textureRect; }

private:
	FloatRect textureRect;
	std::shared_ptr<Texture> pTexture;


	GLuint textureID;
};