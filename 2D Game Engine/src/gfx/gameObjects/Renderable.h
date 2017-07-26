#pragma once

#include <glm/glm.hpp>

#include "../buffers/VertexArray.h"
#include "../../shader/Shader.h"

#include "../structs/Structs.h"

class Renderable
{
public:
	Renderable() = default;

	Renderable( const Position& position, const Size& size )
		: m_Position( position ), m_Size( size ), m_CurrentType( 0 ) {	}

	Renderable( const Position& position, const Size& size, const Colour& colour )
		: m_Position( position ), m_Size( size ), m_Colour( colour ), m_CurrentType( 0 ) {	}

	Renderable( const Position& p1, const Position& p2, const Colour& colour, unsigned short type = 1 )
		: m_P1( p1 ), m_P2( p2 ), m_Colour( colour ) {  m_CurrentType = type; }

	Renderable( const Position& p1, const Position& p2, const Position& p3, const Colour& colour )
		: m_P1( p1 ), m_P2( p2 ), m_P3( p3 ), m_Colour( colour ), m_CurrentType( 0 ) {	}

	virtual ~Renderable() = default;

	virtual void Render( Shader& shader ) = 0;

	const glm::vec3 GetPosition( ) const { return m_Position.ToVec3(); }

	Renderable& operator=( Renderable&& renderable ) = default;

	void SetType( int type ) { m_CurrentType = type; }

protected:
	void RenderIndices( )
	{
		m_IBO.Bind();

		if( m_CurrentType == ShapeType::FILLED )
		{
			glDrawElements( GL_TRIANGLES, m_IBO.GetCount( ), GL_UNSIGNED_INT, nullptr );
		}
		else if( m_CurrentType == ShapeType::LINE )
		{
			glDrawElements( GL_LINE_LOOP, m_IBO.GetCount( ), GL_UNSIGNED_INT, nullptr );
		}

		m_IBO.Unbind();
	}

	void RenderVertices( )
	{
		if( m_CurrentType == ShapeType::FILLED )
		{
			glDrawArrays( GL_TRIANGLES, 0, m_VerticesCount );
		}
		else if( m_CurrentType == ShapeType::LINE )
		{
			glDrawArrays( GL_LINE_LOOP, 0, m_VerticesCount );
		}
	}

protected:
	Position m_Position;
	Colour m_Colour;
	Size m_Size;

	Position m_P1;
	Position m_P2;
	Position m_P3;

	GLuint m_VerticesCount;

	unsigned short m_CurrentType;

	VertexBuffer m_VertVBO;
	VertexBuffer m_ColourVBO;
	IndexBuffer m_IBO;
	VertexArray m_VAO;

protected:
	enum ShaderLocation
	{
		POSITION		= 0,
		COLOUR			= 1,
		TEXTURE_COORD	= 2
	}; 

public:
	enum ShapeType
	{
		FILLED = 0,
		LINE = 1
	};
};