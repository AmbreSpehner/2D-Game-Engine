/**
 *	@file	Texture.h
 *	@author	BouwnLaw
 *	@date	09/07/2017
 *	@brief	Loads a texture.
 *
 *	Loads a texture from a file.
 */
#pragma once

// Include STL
#include <string>

// Include Deps
#include <GL/glew.h>
#include <glm/vec2.hpp>

/**
 *	@brief	Loads a texture.
 *
 *	Loads a texture from a file.
 */
class Texture
{
public:
	/**
	 *	@brief	Constructor.
	 *
	 *	load the texture from a file
	 *
	 *	@param	filepath, path to the file.
	 */
	Texture( const std::string& filepath );

	/**
	 *	@brief	Bind the texture.
	 *
	 *	Bind the texture.
	 */
	void Bind();
	/**
	 *	@brief	Unbind the texture.
	 *
	 *	Unbind the texture.
	 */
	void Unbind();

	/**
	 *	@brief	Get the size of the texture.
	 *
	 *	Get the size of the texture.
	 *
	 *	@return	glm::vec2, size of the texture
	 */
	const glm::vec2 GetSize() const
	{
		return glm::vec2( m_Width, m_Height );
	}

private:
	int m_Width, m_Height;

	GLuint m_TextureID;
};