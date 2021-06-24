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
	Renderer renderer(800, 600);

	Window window(renderer.width, renderer.height, "Rubiks");

	Cube cube;
	cube.rotateFace(cube.greenFace, true);
	//cube.scramble();

	while (!window.ShouldCloseWindow())
	{
		window.ProcessInput(renderer);

		renderer.Clear(0.2f, 0.2f, 0.2f, 1.0f);
		renderer.DrawRubiks(cube);

		window.Update();
	}
}

int main()
{
	bool doGraphics = true;
	if (doGraphics)
	{
		GraphicsStuff();
		Cube cube;
		cube.printCube();
	}
	else
	{
		Cube cube;
		cube.printCube();
		//cube.scramble();
		//cube.printCube();
	}
}
	

