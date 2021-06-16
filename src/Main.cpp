#include "Window.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"

float positions[] =
{
   -0.5f, -0.5f, 0.0f, 0.0f, // 0
   0.5f, -0.5f, 0.0f, 0.0f,
   0.0f, 0.5f, 0.0f, 0.0f
};

unsigned int indices[] =
{
	0, 1, 2
};

int main()
{
	Window window(800, 600, "Rubiks");

	VertexArray va;
	VertexBuffer vb(positions, 3 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 3);

	/*glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	glm::vec3 translation = glm::vec3(0, 0, 0);*/

	Shader shader("shaders/vertex.shader", "shaders/fragment.shader");
	shader.Bind();

	while (!window.ShouldCloseWindow())
	{
		window.ProcessInput();
		Renderer::Draw(va, ib, shader);
		window.Update();
	}
}