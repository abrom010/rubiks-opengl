#pragma once

#include "DebugOpenGL.hpp"

namespace Renderer {
	static void Clear(float r, float g, float b, float a)
	{
		GLCall(glClearColor(r, g, b, a));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	static void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
	{
		shader.Bind();
		va.Bind();
		ib.Bind();
		GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
	}
}
