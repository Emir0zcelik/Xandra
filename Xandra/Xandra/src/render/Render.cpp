#include "GL.h"
#include "Render.h"

void Render::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	shader.Bind();
	va.Bind();
	ib.Bind();

	GL(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Render::Clear() const
{
	GL(glClear(GL_COLOR_BUFFER_BIT));
}