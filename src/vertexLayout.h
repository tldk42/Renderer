//
// Created by kgca44323 on 2024-05-13.
//

#ifndef RENDERER_VERTEXLAYOUT_H
#define RENDERER_VERTEXLAYOUT_H

#include "commonInclude.h"

CLASS_PTR(VertexLayout)
class VertexLayout
{
public:
	static VertexLayoutUPtr Create();
	~VertexLayout();

	uint32_t Get() const { return mVertexArrayObject; }

	void Bind() const;
	void SetAttrib(
		uint32_t attribIndex, int count,
		uint32_t type, bool bNormalized,
		size_t stride, uint64_t offset) const;
	void DisableAttrib(int attribIndex) const;

private:
	VertexLayout() {}
	void Init();

private:
	uint32_t mVertexArrayObject;
};

#endif // RENDERER_VERTEXLAYOUT_H
