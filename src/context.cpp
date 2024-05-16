//
// Created by kgca44323 on 2024-05-13.
//

#include "context.h"

ContextUPtr Context::Create()
{
	ContextUPtr context = ContextUPtr(new Context);

	if (context->Init())
	{
		return std::move(context);
	}

	return nullptr;
}
void Context::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	mProgram->Use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}
bool Context::Init()
{
	float vertices[] = {
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // top right, red
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right, green
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left, blue
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, // top left, yellow
	};
	uint32_t indices[] = {
		// note that we start from 0!
		0, 1, 3, // first triangle
		1, 2, 3, // second triangle
	};

	mVertexLayout = VertexLayout::Create();
	mVertexBuffer = Buffer::CreateWithData(
		GL_ARRAY_BUFFER, GL_STATIC_DRAW,
		vertices, sizeof(float) * 24);

	mVertexLayout->SetAttrib(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
	mVertexLayout->SetAttrib(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, sizeof(float) * 3);

	mIndexBuffer = Buffer::CreateWithData(
		GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW,
		indices, sizeof(uint32_t) * 6);

	ShaderPtr vertShader = Shader::CreateFromFile("../shader/per_vertex_color.vert", GL_VERTEX_SHADER);
	ShaderPtr fragShader = Shader::CreateFromFile("../shader/per_vertex_color.frag", GL_FRAGMENT_SHADER);
	if (!vertShader || !fragShader)
		return false;
	SPDLOG_INFO("vertex shader id: {}", vertShader->Get());
	SPDLOG_INFO("fragment shader id: {}", fragShader->Get());

	mProgram = Program::Create({ fragShader, vertShader });
	if (!mProgram)
		return false;
	SPDLOG_INFO("program id: {}", mProgram->Get());

	glClearColor(0.1f, 0.2f, 0.3f, 0.0f);

	return true;
}
