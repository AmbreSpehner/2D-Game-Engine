#pragma once

#include "../Renderable.h"

class RectangleShape : public Renderable
{
public:
	RectangleShape() = default;
	RectangleShape( const Position& position, const GLf_Size& size, const Colour& colour, unsigned short type = 0 );

	void Render( Shader& shader ) override;

	void SetPosition( const Position& position );
	void SetSize( const GLf_Size& size );
	void SetColour( const Colour& colour );

	const Position& GetPosition( ) const { return position; }
	const GLf_Size& GetSize( ) const { return size; }
	const Colour& GetColour( ) const { return colour; }
};