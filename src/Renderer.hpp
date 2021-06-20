#pragma once

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "VertexBufferLayout.hpp"
#include "Cube.hpp"

class Renderer
{
public:
	int width, height;
	float horizontalRotation, verticalRotation;

	Renderer(int width, int height);
	~Renderer();

	void Clear(float r, float g, float b, float a);
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	void DrawRubiks(const Cube& cube);

};
