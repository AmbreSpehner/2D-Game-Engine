#pragma once

#include "../Renderable.h"

#include "../../buffers/VertexBuffer.h"
#include "../../buffers/IndexBuffer.h"

class RectangleShape : public Renderable
{
public:
	RectangleShape() = default;
	RectangleShape( const GLf_Pos& position, const GLf_Size& size, const GLf_Colour& colour, unsigned short type = 0 );

	void Render( Shader& shader ) override;

	void SetPosition( const GLf_Pos& position );
	void SetSize( const GLf_Size& size );
	void SetColour( const GLf_Colour& colour );

	const GLf_Pos& GetPosition( ) const { return position; }
	const GLf_Size& GetSize( ) const { return size; }
	const GLf_Colour& GetColour( ) const { return colour; }
};