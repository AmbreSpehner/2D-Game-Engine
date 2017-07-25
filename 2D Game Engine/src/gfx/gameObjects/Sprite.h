#pragma once

#include <glm/glm.hpp>

#include "Renderable.h"
#include "../texture/Texture.h"
#include "../shapes/Rect.h"

class Sprite : public Renderable
{
public:
	Sprite() = default;
	Sprite( const Position& m_Position, std::shared_ptr<Texture> pTexture );
	Sprite( const Position& m_Position, const Size& m_Size, std::shared_ptr<Texture> pTexture );

	void Render( Shader& shader ) override;

	void SetPosition( Position& position );
	void SetSize( Size& size );
	void SetColour( Colour& colour );

	const Position& GetPosition( ) const { return m_Position; }
	const Size& GetSize( ) const { return m_Size; }
	const Colour& GetColour( ) const { return m_Colour; }

	void SetTexture( std::shared_ptr<Texture> pTexture );

	void ScaleSprite( float scale );
	
	void SetTextureRect( const FloatRect& rect );
	void SetTextureRect( const float x, const float y, const float dx, const float dy );
	void SetTextureRect( const Position& position, const Size& size );

	void SetTextCoords( const float x, const float y, const float dx, const float dy );
	void SetTextCoords( const Position& position, const Size& size );

	Sprite& operator=( Sprite&& rSprite ) = default;

private:
	float m_Scale;

	VertexBuffer m_TexCoordVBO;
	FloatRect m_TextureRect;

	std::shared_ptr<Texture> m_pTexture;
};