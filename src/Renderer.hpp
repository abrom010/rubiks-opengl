#pragma once

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "VertexBufferLayout.hpp"
#include "Cube.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Arcball.hpp"

class Renderer
{
private:
	
public:
	int width, height;
	ArcballCamera arcball;

	Renderer(int width, int height);
	~Renderer();

	void Clear(float r, float g, float b, float a);
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	void DrawRubiks(const Cube& cube);
};
