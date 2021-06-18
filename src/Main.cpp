#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"

#include "Cube.hpp"

void GraphicsStuff()
{
	Window window(Renderer::WIDTH, Renderer::HEIGHT, "Rubiks");

	Cube cube;

	while (!window.ShouldCloseWindow())
	{
		window.ProcessInput();

		Renderer::Clear(0.3f, 0.3f, 0.3f, 1.0f);
		Renderer::DrawRubiks(cube);

		window.Update();
	}
}

int main()
{
	bool doGraphics = true;
	if (doGraphics)
		GraphicsStuff();

	else
	{
		Cube cube;
		cube.rotateFace(cube.whiteFace, true);
		cube.rotateFace(cube.greenFace, true);
		cube.rotateFace(cube.orangeFace, true);
		cube.rotateFace(cube.yellowFace, true);
		cube.printCube();
	}
}
	

