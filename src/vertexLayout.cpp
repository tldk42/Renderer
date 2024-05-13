//
// Created by kgca44323 on 2024-05-13.
//

#include "vertexLayout.h"

VertexLayoutUPtr VertexLayout::Create()
{
	VertexLayoutUPtr vertexLayout = VertexLayoutUPtr(new VertexLayout);

	vertexLayout->Init();

	return std::move(vertexLayout);
}

void VertexLayout::Bind() const
{
	glBindVertexArray(mVertexArrayObject);
}
void VertexLayout::SetAttrib(uint32_t attribIndex, int count, uint32_t type, bool bNormalized, size_t stride, uint64_t offset) const
{
	glEnableVertexAttribArray(attribIndex);
	glVertexAttribPointer(attribIndex, count,
		type, bNormalized, stride, (const void*)offset);
}
void VertexLayout::DisableAttrib(int attribIndex) const
{
}
void VertexLayout::Init()
{
	glGenVertexArrays(1, &mVertexArrayObject);
	Bind();
}

VertexLayout::~VertexLayout()
{
	if (mVertexArrayObject)
	{
		glDeleteVertexArrays(1, &mVertexArrayObject);
	}
}