//
// Created by kgca44323 on 2024-05-13.
//

#ifndef RENDERER_PROGRAM_H
#define RENDERER_PROGRAM_H

#include "commonInclude.h"
#include "shader.h"

CLASS_PTR(Program)
class Program
{
public:
	static ProgramUPtr Create(const std::vector<ShaderPtr>& shaders);

	~Program();
	uint32_t Get() const { return mProgram; }
	void	 Use() const;

private:
	Program() {}

	bool Link(const std::vector<ShaderPtr>& shaders);

private:
	uint32_t mProgram{ 0 };
};

#endif // RENDERER_PROGRAM_H
