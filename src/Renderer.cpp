#include "Renderer.hpp"



#include "DebugOpenGL.hpp"
#include "Data.hpp"

#include <glm/gtx/string_cast.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Renderer::Renderer(int width, int height)
	: width(width), height(height)
{
}

Renderer::~Renderer()
{
}

void Renderer::Clear(float r, float g, float b, float a)
{
	GLCall(glClearColor(r, g, b, a));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
	GLCall(glClear(GL_DEPTH_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

struct RGBA {
	float r, g, b, a;
};

RGBA GetColorValue(Cube::Color color)
{
	RGBA value = { 0.0f, 0.0f, 0.0f, 1.0f };
	switch (color)
	{
	case Cube::Color::white:
		value = { 1.0f, 1.0f, 1.0f, 1.0f };
		break;
	case Cube::Color::green:
		value = { 0.0f, 1.0f, 0.0f, 1.0f };
		break;
	case Cube::Color::orange:
		value = { 1.0f, 0.65f, 0.0f, 1.0f };
		break;
	case Cube::Color::yellow:
		value = { 1.0f, 1.0f, 0.0f, 1.0f };
		break;
	case Cube::Color::blue:
		value = { 0.0f, 0.0f, 1.0f, 1.0f };
		break;
	case Cube::Color::red:
		value = { 1.0f, 0.0f, 0.0f, 1.0f };
		break;
	}
	return value;
}

void Renderer::DrawRubiks(const Cube& cube)
{
	VertexArray va;

	VertexBuffer squareVertexBuffer(squareVertices, 2 * 4 * sizeof(float));
	VertexBufferLayout squareLayout;
	squareLayout.Push<float>(2);
	va.AddBuffer(squareVertexBuffer, squareLayout);

	VertexBuffer borderVertexBuffer(borderVertices, 2 * 8 * sizeof(float));
	VertexBufferLayout borderLayout;
	borderLayout.Push<float>(2);
	va.AddBuffer(borderVertexBuffer, borderLayout);

	IndexBuffer squareIndexBuffer(squareIndices, 6);		// 6 per square
	IndexBuffer borderIndexBuffer(borderIndices, 6 * 4);

	Shader shader("shaders/vertex.shader", "shaders/fragment.shader");

	//float cameraDistance = -12.25f;

	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 100.0f);

	glm::mat4 view = arcball.transform();

	for (int j = 0; j < 3; j++) // front
	{
		for (int i = 0; i < 3; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);

			model = glm::translate(model, glm::vec3(0, 0, 3.5f));
			model = glm::translate(model, glm::vec3(-2.25f + i * 2.25f, -2.25f + j * 2.25f, 0));

			glm::mat4 mvp = projection * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			RGBA color = GetColorValue(cube.whiteFace[i][j]);

			//draw square
			/*shader.SetUniform4f("u_Color", color.r, color.g, color.b, color.a);
			Draw(va, squareIndexBuffer, shader);*/

			//draw border
			shader.SetUniform4f("u_Color", 0.0f, 0.0f, 0.0f, 1.0f);
			Draw(va, borderIndexBuffer, shader);
		}
	}

	for (int j = 0; j < 3; j++) // right, blue
	{
		for (int i = 0; i < 3; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);

			model = glm::rotate(model, -1.5708f, glm::vec3(0, 0, 1));
			model = glm::rotate(model, -1.5708f, glm::vec3(1, 0, 0));
			model = glm::rotate(model, 1.5708f, glm::vec3(0, 0, 1));

			model = glm::translate(model, glm::vec3(0, 0, 3.5f));
			model = glm::translate(model, glm::vec3(-2.25f + i * 2.25f, -2.25f + j * 2.25f, 0));

			glm::mat4 mvp = projection * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			RGBA color = GetColorValue(cube.blueFace[i][j]);
			
			//draw square
			/*shader.SetUniform4f("u_Color", color.r, color.g, color.b, color.a);
			Draw(va, squareIndexBuffer, shader);*/

			//draw border
			shader.SetUniform4f("u_Color", 0.0f, 0.0f, 0.0f, 1.0f);
			Draw(va, borderIndexBuffer, shader);
		}
	}

	for (int j = 0; j < 3; j++) // left, green
	{
		for (int i = 0; i < 3; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);

			model = glm::rotate(model, -1.5708f, glm::vec3(0, 0, 1));
			model = glm::rotate(model, 1.5708f, glm::vec3(1, 0, 0));
			model = glm::rotate(model, -1.5708f, glm::vec3(0, 0, 1));

			model = glm::translate(model, glm::vec3(0, 0, 3.5f));
			model = glm::translate(model, glm::vec3(-2.25f + i * 2.25f, -2.25f + j * 2.25f, 0));

			glm::mat4 mvp = projection * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			RGBA color = GetColorValue(cube.greenFace[i][j]);
			
			//draw square
			/*shader.SetUniform4f("u_Color", color.r, color.g, color.b, color.a);
			Draw(va, squareIndexBuffer, shader);*/

			//draw border
			shader.SetUniform4f("u_Color", 0.0f, 0.0f, 0.0f, 1.0f);
			Draw(va, borderIndexBuffer, shader);
		}
	}

	for (int j = 0; j < 3; j++) // back, yellow
	{
		for (int i = 0; i < 3; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);

			model = glm::rotate(model, 3.14159f, glm::vec3(1, 0, 0));

			model = glm::translate(model, glm::vec3(0, 0, 3.5f));
			model = glm::translate(model, glm::vec3(-2.25f + i * 2.25f, -2.25f + j * 2.25f, 0));

			glm::mat4 mvp = projection * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			RGBA color = GetColorValue(cube.yellowFace[i][j]);
			
			//draw square
			/*shader.SetUniform4f("u_Color", color.r, color.g, color.b, color.a);
			Draw(va, squareIndexBuffer, shader);*/

			//draw border
			shader.SetUniform4f("u_Color", 0.0f, 0.0f, 0.0f, 1.0f);
			Draw(va, borderIndexBuffer, shader);
		}
	}

	for (int j = 0; j < 3; j++) // bottom, red
	{
		for (int i = 0; i < 3; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);

			model = glm::rotate(model, -1.5708f, glm::vec3(0, 0, 1));
			model = glm::rotate(model, 1.5708f, glm::vec3(0, 1, 0));

			model = glm::translate(model, glm::vec3(0, 0, 3.5f));
			model = glm::translate(model, glm::vec3(-2.25f + i * 2.25f, -2.25f + j * 2.25f, 0));

			glm::mat4 mvp = projection * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			RGBA color = GetColorValue(cube.redFace[i][j]);
			
			//draw square
			/*shader.SetUniform4f("u_Color", color.r, color.g, color.b, color.a);
			Draw(va, squareIndexBuffer, shader);*/

			//draw border
			shader.SetUniform4f("u_Color", 0.0f, 0.0f, 0.0f, 1.0f);
			Draw(va, borderIndexBuffer, shader);
		}
	}

	for (int j = 0; j < 3; j++) // top, orange
	{
		for (int i = 0; i < 3; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);

			model = glm::rotate(model, 1.5708f, glm::vec3(0, 0, 1));
			model = glm::rotate(model, 1.5708f, glm::vec3(0, 1, 0));

			model = glm::translate(model, glm::vec3(0, 0, 3.5f));
			model = glm::translate(model, glm::vec3(-2.25f + i * 2.25f, -2.25f + j * 2.25f, 0));

			glm::mat4 mvp = projection * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			RGBA color = GetColorValue(cube.orangeFace[i][j]);
			
			//draw square
			/*shader.SetUniform4f("u_Color", color.r, color.g, color.b, color.a);
			Draw(va, squareIndexBuffer, shader);*/

			//draw border
			shader.SetUniform4f("u_Color", 0.0f, 0.0f, 0.0f, 1.0f);
			Draw(va, borderIndexBuffer, shader);
		}
	}

}
