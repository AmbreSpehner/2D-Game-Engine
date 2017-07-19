/**
 *	@file		Shader.h
 *	@Author		BouwnLaw
 *	@date		07/07/2017
 *	@brief		Create a load a vertex shader and a fragment shader.
 *
 *	Create a load a vertex shader and a fragment shader and allow the use
 *	of the shaders.
 */

#pragma once

// Include STL
#include <string>

// Include Deps
#include <gl/glew.h>
#include <glm/glm.hpp>

/**
 *	@brief	Create a shader object.
 *
 *	Create a shader object using a vertex shader and a fragment shader.
 */
class Shader
{
public:
	/**
	 *	@brief	Constructor.
	 *
	 *	Create the shader ID.
	 *
	 *	@param	vertexPath, path to the vertex shader file.
	 *	@param	fragmentPath, path to the fragment shader file.
	 */
	Shader( const std::string& vertexPath, const std::string& fragmentPath );
	/**
	 *	@brief Destructor.
	 *
	 *	Destroy the shader ID.
	 */
	~Shader();

	/**
	 *	@brief Enable the shader.
	 *
	 *	Install the program object using the current shader ID.
	 */
	void Enable() const;
	/**
	 *	@brief Disable the shader.
	 *
	 *	Uninstall the program object.
	 */
	void Disable() const;

	/**
	 *	@brief	Set a float mat4 to a uniform in the shader.
	 *
	 *	Set the value of a float mat4 to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	matrix, Value to be set
	 */
	void SetUniformMat4f( const std::string& name, const glm::mat4& matrix );
	/**
	 *	@brief	Set a float mat3 to a uniform in the shader.
	 *
	 *	Set the value of a float mat3 to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	matrix, Value to be set
	 */
	void SetUniformMat3f( const std::string& name, const glm::mat3& matrix );

	/**
	 *	@brief	Set a float vec4 to a uniform in the shader.
	 *
	 *	Set the value of a float vec4 to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	vector, Value to be set
	 */
	void SetUniformVec4f( const std::string& name, const glm::vec4& vector );
	/**
	 *	@brief	Set a int vec4 to a uniform in the shader.
	 *
	 *	Set the value of a int vec4 to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	vector, Value to be set
	 */
	void SetUniformVec4i( const std::string& name, const glm::vec4& vector );

	/**
	 *	@brief	Set a float vec3 to a uniform in the shader.
	 *
	 *	Set the value of a float vec3 to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	vector, Value to be set
	 */
	void SetUniformVec3f( const std::string& name, const glm::vec3& vector );
	/**
	 *	@brief	Set a int vec3 to a uniform in the shader.
	 *
	 *	Set the value of a int vec3 to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	vector, Value to be set
	 */
	void SetUniformVec3i( const std::string& name, const glm::vec3& vector );

	/**
	 *	@brief	Set a float vec2 to a uniform in the shader.
	 *
	 *	Set the value of a float vec2 to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	vector, Value to be set
	 */
	void SetUniformVec2f( const std::string& name, const glm::vec2& vector );
	/**
	 *	@brief	Set a int vec2 to a uniform in the shader.
	 *
	 *	Set the value of a int vec2 to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	vector, Value to be set
	 */
	void SetUniformVec2i( const std::string& name, const glm::vec2& vector );

	/**
	 *	@brief	Set a float to a uniform in the shader.
	 *
	 *	Set the value of a float to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	value, Value to be set
	 */
	void SetUniform1f( const std::string& name, const float value );
	/**
	 *	@brief	Set an int to a uniform in the shader.
	 *
	 *	Set the value of an int to a uniform variable for
	 *	the current shader.
	 *
	 *	@param	name, Name of the uniform variable
	 *	@param	value, Value to be set
	 */
	void SetUniform1i( const std::string& name, const int value );

private:
	/**
	 *	@brief	Load the shaders.
	 *
	 *	Load the shaders. Compile them and check for any errors in the shader file.
	 *
	 *	@param, vertexPath, path to the vertex shader file
	 *	@param, fragmentPath, path to the fragment shader file
	 *
	 *	@return	GLuint, program id
	 */
	GLuint LoadShaders( const std::string& vertexPath, const std::string& fragmentPath );
	/**
	 *	@brief	Retrieve a uniform location withing the shader file.
	 *
	 *	Retrieve the location of a desired uniform within the shaders
	 *
	 *	@param	name, Name of the uniform to be retrieved.
	 *
	 *	@return, GLint, location of the uniform.
	 */
	GLint GetUniformLocation( const std::string& name );

private:
	GLuint m_ShaderID;
};