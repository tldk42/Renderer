//
// Created by kgca44323 on 2024-05-13.
//

#include "program.h"

ProgramUPtr Program::Create(const std::vector<ShaderPtr>& shaders)
{
	ProgramUPtr program = ProgramUPtr(new Program);

	if (program->Link(shaders))
	{
		return std::move(program);
	}

	return nullptr;
}

void Program::Use() const
{
	if (mProgram)
	{
		glUseProgram(mProgram);
	}
}
bool Program::Link(const std::vector<ShaderPtr>& shaders)
{
	mProgram = glCreateProgram();

	for (const ShaderPtr& shader : shaders)
	{
		glAttachShader(mProgram, shader->Get());
	}
	glLinkProgram(mProgram);

	int success = 0;
	glGetProgramiv(mProgram, GL_LINK_STATUS, &success);

	if (success)
	{
		return true;
	}

	char infoLog[1024];
	glGetProgramInfoLog(mProgram, 1024, nullptr, infoLog);
	SPDLOG_ERROR("failed to link program: {}", infoLog);

	return false;
}

Program::~Program()
{
	if (mProgram)
	{
		glDeleteProgram(mProgram);
	}
}
