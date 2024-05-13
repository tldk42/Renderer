//
// Created by kgca44323 on 2024-05-13.
//

#include "shader.h"

ShaderUPtr Shader::CreateFromFile(const std::string& fileName, GLenum shaderType)
{
	std::unique_ptr<Shader> shader = std::unique_ptr<Shader>(new Shader());

	if (shader->LoadFile(fileName, shaderType))
	{
		return std::move(shader);
	}

	return nullptr;
}

bool Shader::LoadFile(const std::string& fileName, GLenum shaderType)
{
	std::optional<std::string> loadResult = HelperLibrary::LoadTextFile(fileName);

	if (loadResult.has_value())
	{
		std::string& textString = loadResult.value();
		const char*	 codePtr = textString.c_str();

		int32_t textLength = (int32_t)textString.length();

		mShader = glCreateShader(shaderType);
		glShaderSource(mShader, 1, (const GLchar* const*)&codePtr, &textLength);
		glCompileShader(mShader);

		int success = 0;
		glGetShaderiv(mShader, GL_COMPILE_STATUS, &success);

		if (success)
		{
			return true;
		}
	}
	char infoLog[1024];
	glGetShaderInfoLog(mShader, 1024, nullptr, infoLog);
	SPDLOG_ERROR("failed to compile shader: \"{}\"", fileName);
	SPDLOG_ERROR("reason: {}", infoLog);

	return false;
}
Shader::~Shader()
{
	if (mShader)
	{
		glDeleteShader(mShader);
	}
}
