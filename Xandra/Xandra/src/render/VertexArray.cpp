#include "GL.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"


VertexArray::VertexArray()
{
	GL(glGenVertexArrays(1, &_renderID));
}

VertexArray::~VertexArray()
{
	GL(glDeleteVertexArrays(1, &_renderID));
}


void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{

	Bind();

	vb.Bind();

	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {

		const auto& element = elements[i];
		GL(glEnableVertexAttribArray(i));
		GL(glVertexAttribPointer(i, element.count, element.type,
			element.normalized, layout.GetStride(), (const void*)offset));
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const
{
	GL(glBindVertexArray(_renderID));
}

void VertexArray::Unbind() const
{
	GL(glBindVertexArray(0));
}

