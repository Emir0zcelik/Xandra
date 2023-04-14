#pragma once

#include "GL.h"

#include <vector>

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT: return sizeof(float);
		case GL_UNSIGNED_INT: return sizeof(unsigned int);
		case GL_UNSIGNED_BYTE: return sizeof(unsigned char);
		}
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> _Elements;
	unsigned int _Stride;
public:

	VertexBufferLayout() : _Stride(0) {}

	template<typename T>
	void Push(unsigned int count)
	{
		ASSERT(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
		_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_FALSE });
		_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector <VertexBufferElement> GetElements() const { return _Elements; }

	inline unsigned int GetStride() const { return _Stride; }

};