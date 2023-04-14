#include "GL.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GL(glCreateBuffers(1, &_renderID));
	GL(glBindBuffer(GL_ARRAY_BUFFER, _renderID));
	GL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	GL(glDeleteBuffers(1, &_renderID));
}

void VertexBuffer::Bind() const
{
	GL(glBindBuffer(GL_ARRAY_BUFFER, _renderID));
}

void VertexBuffer::Unbind() const
{
	GL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}