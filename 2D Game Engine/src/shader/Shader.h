#pragma once

#include <string>

#include <gl/glew.h>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader( const std::string& vertexPath, const std::string& fragmentPath );
	~Shader();

	void Enable() const;
	void Disable() const;

	void SetUniformMat4f( const std::string& name, const glm::mat4& matrix );
	void SetUniformMat3f( const std::string& name, const glm::mat3& matrix );

	void SetUniformVec4f( const std::string& name, const glm::vec4& vector );
	void SetUniformVec4i( const std::string& name, const glm::vec4& vector );
	void SetUniformVec3f( const std::string& name, const glm::vec3& vector );
	void SetUniformVec3i( const std::string& name, const glm::vec3& vector );
	void SetUniformVec2f( const std::string& name, const glm::vec2& vector );
	void SetUniformVec2i( const std::string& name, const glm::vec2& vector );
	void SetUniform1f( const std::string& name, const float value );
	void SetUniform1i( const std::string& name, const int value );

private:
	GLuint LoadShaders( const std::string& vertexPath, const std::string& fragmentPath );

	GLint GetUniformLocation( const std::string& name );

private:
	GLuint m_ShaderID;
};