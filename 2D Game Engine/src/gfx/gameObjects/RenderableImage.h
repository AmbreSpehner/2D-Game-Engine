#pragma once

#include "Renderable.h"
#include "../texture/Texture.h"
#include "../../collision/shapes/Rect.h"

class RenderableImage : public Renderable
{
public:
	RenderableImage( );
	RenderableImage( const GLf_Pos& position, const GLf_Size& size, const GLf_Colour& colour, std::shared_ptr<Texture> pTexture, unsigned short type = 0.0f );

	void Render( Shader& shader );

	void SetPosition( const GLf_Pos& position );
	void SetSize( const GLf_Size& size );
	void SetColour( const GLf_Colour& colour );
	void SetTextureRect( const FloatRect& rect );
	void SetTexture( const std::shared_ptr<Texture> pTexture );

	const GLf_Pos& GetPosition( ) const { return position; }
	const GLf_Size& GetSize( ) const { return size; }
	const GLf_Colour& GetColour( ) const { return colour; }
	const FloatRect& GetRect( ) const { return textureRect; }

private:
	FloatRect textureRect;
	std::shared_ptr<Texture> pTexture;


	GLuint textureID;
};