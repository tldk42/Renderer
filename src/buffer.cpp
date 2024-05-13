//
// Created by kgca44323 on 2024-05-13.
//

#include "buffer.h"

BufferUPtr Buffer::CreateWithData(uint32_t bufferType, uint32_t usage, const void* data, size_t dataSize)
{
	BufferUPtr buffer = BufferUPtr(new Buffer);

	if (buffer->Init(bufferType, usage, data, dataSize))
	{
		return std::move(buffer);
	}
	return nullptr;
}

void Buffer::Bind() const
{
	glBindBuffer(mBufferType, mBuffer);
}
bool Buffer::Init(uint32_t bufferType, uint32_t usage, const void* data, size_t dataSize)
{
	mBufferType = bufferType;
	mUsage = usage;
	glGenBuffers(1, &mBuffer);
	Bind();
	glBufferData(mBufferType, dataSize, data, usage);

	return true;
}

Buffer::~Buffer()
{
	if (mBuffer)
	{
		glDeleteBuffers(1, &mBuffer);
	}
}
