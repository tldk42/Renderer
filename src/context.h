//
// Created by kgca44323 on 2024-05-13.
//

#ifndef RENDERER_CONTEXT_H
#define RENDERER_CONTEXT_H

#include "commonInclude.h"
#include "program.h"
#include "vertexLayout.h"
#include "buffer.h"

CLASS_PTR(Context)
class Context
{
public:
	static ContextUPtr Create();
	void			   Render();

private:
	Context() {}

	bool Init();

private:
	ProgramUPtr mProgram;

	VertexLayoutUPtr mVertexLayout;
	BufferUPtr		 mVertexBuffer;
	BufferUPtr		 mIndexBuffer;
};

#endif // RENDERER_CONTEXT_H
