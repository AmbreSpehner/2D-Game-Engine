#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "../buffers/VertexArray.h"
#include "../../shader/Shader.h"

#include "../structs/Structs.h"

class Renderable
{
public:
	Renderable() = default;

	Renderable( const Position& position, const GLf_Size& size, unsigned short type = 0 )
		: position( position ), size( size ), currentType( type ) {	}

	Renderable( const Position& position, const GLf_Size& size, const Colour& colour, unsigned short type = 0 )
		: position( position ), size( size ), colour( colour ), currentType( type ) {	}

	Renderable( const Point<GLfloat>& p1, const Point<GLfloat>& p2, const Colour& colour, unsigned short type = 1 )
		: p1( p1 ), p2( p2 ), colour( colour ), currentType( type ) {	}

	Renderable( const Point<GLfloat>& p1, const Point<GLfloat>& p2, const Point<GLfloat>& p3, const Colour& colour, unsigned short type = 0 )
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
			throw std::out_of_range{ "The type of rendering specified does not match the available types!\n" };

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
			throw std::out_of_range{ "The type of rendering specified does not match the available types!\n" };
	}

protected:
	Position position;
	Colour colour;
	GLf_Size size;

	Point<GLfloat> p1;
	Point<GLfloat> p2;
	Point<GLfloat> p3;

	GLuint verticesCount;

	unsigned short currentType;
	float lineWidth;

	std::vector<GLfloat> vertices =
	{
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 0.0f
	};

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