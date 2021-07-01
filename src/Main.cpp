#include "Window.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"

#include "Cube.hpp"

int main()
{
	Renderer renderer(800, 600);

	Cube cube;
	Window window(renderer.width, renderer.height, "Rubiks", cube);

	while (!window.ShouldCloseWindow())
	{
		window.ProcessInput(renderer);

		renderer.Clear(0.7f, 1.0f, 1.0f, 1.0f);
		renderer.DrawRubiks(cube);

		window.Update();
	}
}