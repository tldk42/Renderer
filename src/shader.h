//
// Created by kgca44323 on 2024-05-13.
//

#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

#include "commonInclude.h"

CLASS_PTR(Shader);
class Shader
{
private:
	Shader(){};

public:
	~Shader();

	static ShaderUPtr CreateFromFile(const std::string& fileName, GLenum shaderType);

	uint32_t Get() const { return mShader; }

private:
	bool	 LoadFile(const std::string& fileName, GLenum shaderType);
	uint32_t mShader{ 0 };
};

#endif // RENDERER_SHADER_H
