#include "Shader.h"

#include <iostream>
#include <vector>

#include <glm/gtc/type_ptr.hpp>

#include "../utils/File_Reader.h"

Shader::Shader( const std::string & vertexPath, const std::string & fragmentPath )
{
	shaderID = LoadShaders( vertexPath, fragmentPath );
}

Shader::~Shader()
{
	glDeleteProgram( shaderID );
}

void Shader::Enable() const
{
	glUseProgram( shaderID );
}

void Shader::Disable() const
{
	glUseProgram( 0 );
}

GLuint Shader::LoadShaders( const std::string & vertexPath, const std::string & fragmentPath )
{
	// Create the shaders.
	GLuint vertexShaderID = glCreateShader( GL_VERTEX_SHADER );
	GLuint fragmentShaderID = glCreateShader( GL_FRAGMENT_SHADER );

	// Load the shaders.
	std::string vertexFile = File_Reader( vertexPath );
	std::string fragmentFile = File_Reader( fragmentPath );

	const char* vertexSource = vertexFile.c_str();
	const char* fragmentSource = fragmentFile.c_str();

	GLint result;

	// compile vertex shader.
	glShaderSource( vertexShaderID, 1, &vertexSource, NULL );
	glCompileShader( vertexShaderID );

	// Check if vertex shader compiled properly.
	glGetShaderiv( vertexShaderID, GL_COMPILE_STATUS, &result );
	if ( result == GL_FALSE )
	{
		GLint infoLogLength;
		glGetShaderiv( vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength );
		std::vector<GLchar> error( infoLogLength );
		glGetShaderInfoLog( vertexShaderID, infoLogLength, &infoLogLength, &error[0] );
		std::cout << &error[0] << '\n';
		glDeleteShader( vertexShaderID );
	}

	// Compile fragment shader.
	glShaderSource( fragmentShaderID, 1, &fragmentSource, NULL );
	glCompileShader( fragmentShaderID );

	// Check if fragment shader compiled properly.
	glGetShaderiv( fragmentShaderID, GL_COMPILE_STATUS, &result );
	if ( result == GL_FALSE )
	{
		GLint infoLogLength;
		glGetShaderiv( fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength );
		std::vector<GLchar> error( infoLogLength );
		glGetShaderInfoLog( fragmentShaderID, infoLogLength, &infoLogLength, &error[0] );
		std::cout << &error[0] << '\n';
		glDeleteShader( vertexShaderID );
	}

	// Link the program.
	GLuint programID = glCreateProgram();
	glAttachShader( programID, vertexShaderID );
	glAttachShader( programID, fragmentShaderID );

	glLinkProgram( programID );
	glValidateProgram( programID );

	glDetachShader( programID, vertexShaderID );
	glDetachShader( programID, fragmentShaderID );
	
	glDeleteShader( vertexShaderID );
	glDeleteShader( fragmentShaderID );

	return programID;
}

GLint Shader::GetUniformLocation( const std::string & name )
{
	auto nameBis = name.c_str();

	return glGetUniformLocation( shaderID, nameBis );
}

void Shader::SetUniformMat4f( const std::string & name, const glm::mat4 & matrix )
{
	glUniformMatrix4fv( GetUniformLocation( name ), 1, GL_FALSE, glm::value_ptr( matrix ) );
}

void Shader::SetUniformMat3f( const std::string & name, const glm::mat3 & matrix )
{
	glUniformMatrix3fv( GetUniformLocation( name ), 1, GL_FALSE, glm::value_ptr( matrix ) );
}

void Shader::SetUniformVec4f( const std::string & name, const glm::vec4 & vector )
{
	glUniform4f( GetUniformLocation( name ), vector.x, vector.y, vector.z, vector.w );
}

void Shader::SetUniformVec4i( const std::string & name, const glm::vec4 & vector )
{
	glUniform4i( GetUniformLocation( name ), ( GLint ) vector.x, ( GLint ) vector.y, ( GLint ) vector.z, ( GLint ) vector.w );
}

void Shader::SetUniformVec3f( const std::string & name, const glm::vec3 & vector )
{
	glUniform3f( GetUniformLocation( name ), vector.x, vector.y, vector.z );
}

void Shader::SetUniformVec3i( const std::string & name, const glm::vec3 & vector )
{
	glUniform3i( GetUniformLocation( name ), ( GLint ) vector.x, ( GLint ) vector.y, ( GLint ) vector.z );
}

void Shader::SetUniformVec2f( const std::string & name, const glm::vec2 & vector )
{
	glUniform2f( GetUniformLocation( name ), vector.x, vector.y );
}

void Shader::SetUniformVec2i( const std::string & name, const glm::vec2 & vector )
{
	glUniform2i( GetUniformLocation( name ), ( GLint ) vector.x, ( GLint ) vector.y );
}

void Shader::SetUniform1f( const std::string & name, const float value )
{
	glUniform1f( GetUniformLocation( name ), value );
}

void Shader::SetUniform1i( const std::string & name, const int value )
{
	glUniform1i( GetUniformLocation( name ), value );
}
