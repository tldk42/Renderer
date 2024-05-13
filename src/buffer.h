//
// Created by kgca44323 on 2024-05-13.
//

#ifndef RENDERER_BUFFER_H
#define RENDERER_BUFFER_H

#include "commonInclude.h"

CLASS_PTR(Buffer)
class Buffer
{
public:
	static BufferUPtr CreateWithData(uint32_t bufferType, uint32_t usage, const void* data, size_t dataSize);
	~Buffer();

	uint32_t Get() const { return mBuffer; }
	void	 Bind() const;

private:
	Buffer() {}

	bool Init(uint32_t bufferType, uint32_t usage, const void* data, size_t dataSize);

private:
	uint32_t mBuffer{ 0 };
	uint32_t mBufferType{ 0 };
	uint32_t mUsage{ 0 };
};

#endif // RENDERER_BUFFER_H
