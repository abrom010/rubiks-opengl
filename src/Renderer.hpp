#pragma once

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "VertexBufferLayout.hpp"
#include "Cube.hpp"

class Renderer
{
private:
	float yaw, pitch, roll;
public:
	int width, height;
	float horizontalRotation, verticalRotation;
	float manualDepthRotation;

	Renderer(int width, int height);
	~Renderer();

	void Clear(float r, float g, float b, float a);
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	void DrawRubiks(const Cube& cube);

	void UpdateRotation();
};
