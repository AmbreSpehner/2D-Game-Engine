#pragma once

#include "../Renderable.h"

#include "../../buffers/VertexBuffer.h"
#include "../../buffers/IndexBuffer.h"

class RectangleShape : public Renderable
{
public:
	RectangleShape() = default;
	RectangleShape( const Position& position, const Size& size, const Colour& colour );

	void Render( Shader& shader ) override;

	void SetPosition( const Position& position );
	void SetSize( const Size& size );
	void SetColour( const Colour& colour );

	const Position& GetPosition( ) const { return m_Position; }
	const Size& GetSize( ) const { return m_Size; }
	const Colour& GetColour( ) const { return m_Colour; }
};