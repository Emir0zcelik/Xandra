#include "GL.h"
#include "IndexBuffer.h"


IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : _count(count)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint))

	GL(glGenBuffers(1, &_renderID));
	GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderID));
	GL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GL(glDeleteBuffers(1, &_renderID));
}

void IndexBuffer::Bind() const
{
	GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderID));
}

void IndexBuffer::Unbind() const
{
	GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::GetCount() const
{
	return _count;
}