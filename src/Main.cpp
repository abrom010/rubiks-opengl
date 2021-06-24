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

	Window window(renderer.width, renderer.height, "Rubiks");

	Cube cube;
	//cube.rotateFace(cube.greenFace, true);

	while (!window.ShouldCloseWindow())
	{
		window.ProcessInput(renderer);

		renderer.Clear(0.2f, 0.2f, 0.2f, 1.0f);
		renderer.DrawRubiks(cube);

		window.Update();
	}
}
	

