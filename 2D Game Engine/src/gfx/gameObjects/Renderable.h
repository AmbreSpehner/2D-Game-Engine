/**
 *	@file	Renderable.h
 *	@author	BouwnLaw
 *	@date	09/07/2017
 *	@brief	Base class for all square objects to be rendered.
 *
 *	Base class for all square objects to be rendered.
 */
#pragma once

// Include Deps
#include <glm/glm.hpp>

// Include Project
#include "../buffers/VertexArray.h"
#include "../../shader/Shader.h"

#include <iostream>

/**
 *	@brief	Base class for all square objects to be rendered.
 *
 *	Base class for all square objects to be rendered.
 */
class Renderable
{
public:
	/**
	 *	@brief	Constructor.
	 *	
	 *	Default constructor.
	 */
	Renderable() = default;
	/**
	 *	@brief	Constructor.
	 *
	 *	Set the position and size of a rectangular shaped object.
	 *
	 *	@param	position, vec3 position of the renderable
	 *	@param	size, vec2 size of the renderable
	 */
	Renderable( const glm::vec3& position, const glm::vec2& size )
		: m_Position( position ), m_Size( size )
	{ m_CurrentType = 0; }
	/**
	 *	@brief	Constructor.
	 *
	 *	Set the position and size of a rectangular shaped object.
	 *
	 *	@param	position, vec3 position of the renderable
	 *	@param	size, vec2 size of the renderable
	 *	@param	tipe, type of rendering
	 */
	Renderable( const glm::vec3& position, const glm::vec2& size, int type )
		: m_Position( position ), m_Size( size ), m_CurrentType( type ) 
	{	}
	/**
	 *	@brief	Constructor.
	 *
	 *	Set the position, size and colour of a rectangular shaped object.
	 *
	 *	@param	position, vec3 position of the renderable
	 *	@param	size, vec2 size of the renderable
	 *	@param	colour, vec4 colour of the renderable
	 */
	Renderable( const glm::vec3& position, const glm::vec2& size, const glm::vec4& colour )
		: m_Position( position ), m_Size( size ), m_Colour( colour )
	{ m_CurrentType = 0; }
	/**
	 *	@brief	Constructor.
	 *
	 *	Set the position, size and colour of a rectangular shaped object.
	 *
	 *	@param	position, vec3 position of the renderable
	 *	@param	size, vec2 size of the renderable
	 *	@param	colour, vec4 colour of the renderable
	 */
	Renderable( const glm::vec3& position, const glm::vec2& size, const glm::vec4& colour, int type )
		: m_Position( position ), m_Size( size ), m_Colour( colour ), m_CurrentType( type )
	{	}
	/**
	 *	@brief	Constructor.
	 *
	 *	Set the position of the vertices and the colour of a triangular shape.
	 *
	 *	@param	vertPos1, first vertex position
	 *	@param	vertPos2, second vertex position
	 *	@param	vertPos3, third vertex position
	 *	@param	colour, colour of the renderable
	 */
	Renderable( const glm::vec3& vertPos1, const glm::vec3& vertPos2, const glm::vec3& vertPos3, const glm::vec4& colour )
		: m_VertPos1( vertPos1 ), m_VertPos2( vertPos2 ), m_VertPos3( vertPos3 ), m_Colour( colour )
	{ m_CurrentType = 0; }
	/**
	 * @brief	Constructor.
	 *
	 *	Set the position of the vertices, the colour and the rendering type of a triangular shape.
	 *
	 *	@param	vertPos1, first vertex position
	 *	@param	vertPos2, second vertex position
	 *	@param	vertPos3, third vertex position
	 *	@param	colour, colour of the renderable
	 *	@param	type, rendering type
	 */
	Renderable( const glm::vec3& vertPos1, const glm::vec3& vertPos2, const glm::vec3& vertPos3, const glm::vec4& colour, int type )
		: m_VertPos1( vertPos1 ), m_VertPos2( vertPos2 ), m_VertPos3( vertPos3 ), m_Colour( colour ), m_CurrentType( type )
	{	}

	Renderable( std::vector<glm::vec3>& vertPos, glm::vec4& colour )
		: m_VertPos( vertPos ), m_Colour( colour )
	{	}

	Renderable( std::vector<glm::vec3>& vertPos, glm::vec4& colour, int type )
		: m_VertPos( vertPos ), m_Colour( colour ), m_CurrentType( type )
	{	}

	/**
	 *	@brief	Destructor.
	 *
	 *	Virtual destructor.
	 */
	virtual ~Renderable() = default;

	virtual void Render( Shader& shader ) = 0;

	const glm::vec3& GetPosition( ) const { return m_Position; }

	/**
	*	@brief	Default move operator.
	*
	*	Default move operator.
	*
	*	@return	renderable, rvalue renderable object
	*/
	Renderable& operator=( Renderable&& renderable ) = default;

	/**
	 *	@brief	Set the type of rendering desired.
	 *
	 *	Set the type of rendering desired.
	 *
	 *	@param	type, type of rendering
	 */
	void SetType( int type )
	{
		m_CurrentType = type;
	}

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
	glm::vec3 m_Position;
	glm::vec2 m_Size;
	glm::vec4 m_Colour;

	glm::vec3 m_VertPos1;
	glm::vec3 m_VertPos2;
	glm::vec3 m_VertPos3;

	std::vector<glm::vec3> m_VertPos;

	GLuint m_VerticesCount;

	int m_CurrentType;

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