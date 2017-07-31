#pragma once

#include <glm/glm.hpp>

#include "../buffers/VertexArray.h"
#include "../../shader/Shader.h"

#include "../structs/Structs.h"

class Renderable
{
public:
	Renderable() = default;

	Renderable( const GLf_Pos& position, const GLf_Size& size, unsigned short type = 0 )
		: position( position ), size( size ), currentType( type ) {	}

	Renderable( const GLf_Pos& position, const GLf_Size& size, const GLf_Colour& colour, unsigned short type = 0 )
		: position( position ), size( size ), colour( colour ), currentType( type ) {	}

	Renderable( const GLf_Pos& p1, const GLf_Pos& p2, const GLf_Colour& colour, unsigned short type = 1 )
		: p1( p1 ), p2( p2 ), colour( colour ), currentType( type ) {	}

	Renderable( const GLf_Pos& p1, const GLf_Pos& p2, const GLf_Pos& p3, const GLf_Colour& colour, unsigned short type = 0 )
		: p1( p1 ), p2( p2 ), p3( p3 ), colour( colour ), currentType( type ) {	}

	virtual ~Renderable() = default;

	virtual void Render( Shader& shader ) = 0;

	const glm::vec3 GetPosition( ) const { return static_cast<glm::vec3>( position ); }

	Renderable& operator=( Renderable&& renderable ) = default;

	void SetType( int type ) { currentType = type; }

protected:
	void RenderIndices( )
	{
		IBO.Bind();

		if( currentType == ShapeType::FILLED )
		{
			glDrawElements( GL_TRIANGLES, IBO.GetCount( ), GL_UNSIGNED_INT, nullptr );
		}
		else if( currentType == ShapeType::LINE )
		{
			glDrawElements( GL_LINE_LOOP, IBO.GetCount( ), GL_UNSIGNED_INT, nullptr );
		}
		else
		{
			throw std::out_of_range{ "The type of rendering specified does not match the available types!\n" };
		}

		IBO.Unbind();
	}

	void RenderVertices( )
	{
		if( currentType == ShapeType::FILLED )
		{
			glDrawArrays( GL_TRIANGLES, 0, verticesCount );
		}
		else if( currentType == ShapeType::LINE )
		{
			glDrawArrays( GL_LINE_LOOP, 0, verticesCount );
		}
		else
		{
			throw std::out_of_range{ "The type of rendering specified does not match the available types!\n" };
		}
	}

protected:
	GLf_Pos position;
	GLf_Size size;
	GLf_Colour colour;

	GLf_Pos p1;
	GLf_Pos p2;
	GLf_Pos p3;

	GLuint verticesCount;

	unsigned short currentType;
	float lineWidth;

	VertexBuffer vertVBO;
	VertexBuffer colourVBO;
	VertexBuffer texCoordVBO;

	IndexBuffer IBO;
	
	VertexArray VAO;

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