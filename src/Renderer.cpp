#include "Renderer.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "DebugOpenGL.hpp"
#include "Data.hpp"
#include "Cube.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "VertexBufferLayout.hpp"

Renderer::Renderer(int width, int height)
{
	this->width = width;
	this->height = height;
}

Renderer::~Renderer()
{
}

void Renderer::Clear(float r, float g, float b, float a)
{
	GLCall(glClearColor(r, g, b, a));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::DrawRubiks(const Cube& cube)
{
	VertexArray va;
	VertexBuffer vb(vertices, 4 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);

	Shader shader("shaders/vertex.shader", "shaders/fragment.shader");

	{
		glm::mat4 projection = glm::perspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 100.0f);
		//glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 model = glm::mat4(1.0f);

		view = glm::translate(view, glm::vec3(0, 0, -2));
		//view = glm::rotate(view, 0.610865f, glm::vec3(0, 1, 0));
		//view = glm::rotate(view, 0.610865f, glm::vec3(0, 1, 0)) * glm::lookAt(glm::vec3(0, 0, -2), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

		model = glm::rotate(model, 0.610865f, glm::vec3(0, 1, 0));
		model = glm::rotate(model, 0.610865f, glm::vec3(0, -1, 0));
		model = glm::translate(model, glm::vec3(0, 0, -1));

		glm::mat4 mvp = projection * view * model;
		shader.Bind();
		shader.SetUniformMat4f("u_MVP", mvp);
		shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
		Draw(va, ib, shader);
	}

	/*{
		glm::mat4 proj = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 1.0f, 150.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 model = glm::mat4(1.0f);

		view = glm::rotate(view, glm::pi<float>() / 2.0f, glm::vec3(0, 1, 0));
		view = glm::translate(view, glm::vec3(0, 0, -1));

		model = glm::translate(model, glm::vec3(0, 0, 0));

		glm::mat4 mvp = proj * view * model;
		shader.Bind();
		shader.SetUniformMat4f("u_MVP", mvp);
		shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
		Draw(va, ib, shader);
	}*/
	/*for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			glm::mat4 proj = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 1.0f, 150.0f);
			glm::mat4 view = glm::mat4(1.0f);
			glm::mat4 model = glm::mat4(1.0f);

			view = glm::rotate(view, glm::pi<float>() / 2.0f, glm::vec3(0, 1, 0));
			view = glm::translate(view, glm::vec3(0, 0, -1));

			model = glm::rotate(model, glm::pi<float>() / 2.0f, glm::vec3(0, 1, 0));
			model = glm::translate(model, glm::vec3(-2.5f + i*2.5f, -2.5f + j*2.5f, 0));

			glm::mat4 mvp = proj * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
			Draw(va, ib, shader);
		}
	}*/

	/*for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			glm::mat4 proj = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 1.0f, 150.0f);
			glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -1));
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::translate(model, glm::vec3(-2.5f + i * 2.5f, -2.5f + j * 2.5f, 0));

			glm::mat4 mvp = proj * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
			Draw(va, ib, shader);
		}
	}*/




}