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

#include "Data.hpp"

int WIDTH = 800;
int HEIGHT = 600;

void GraphicsStuff()
{
	Window window(WIDTH, HEIGHT, "Rubiks");

	VertexArray va;
	VertexBuffer vb(vertices, 4 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);

	glm::mat4 proj = glm::perspective(40.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 1.0f, 150.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -1));
	glm::mat4 model = glm::mat4(1.0f);
	//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 mvp = proj * view * model;

	Shader shader("shaders/vertex.shader", "shaders/fragment.shader");
	shader.Bind();
	shader.SetUniformMat4f("u_MVP", mvp);

	while (!window.ShouldCloseWindow())
	{
		window.ProcessInput();

		Renderer::Clear(0.3f, 0.3f, 0.3f, 1.0f);
		Renderer::Draw(va, ib, shader);

		window.Update();
	}
}

int main()
{
	bool doGraphics = false;
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
	

