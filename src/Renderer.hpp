#pragma once

class Renderer
{
public:
	int width, height;

	Renderer(int width, int height);
	~Renderer();

	void Clear(float r, float g, float b, float a);
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	void DrawRubiks(const Cube& cube);

};
