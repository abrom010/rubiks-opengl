#pragma once

#include "DebugOpenGL.hpp"

#include "Data.hpp"
#include "Cube.hpp"

namespace Renderer {

	int WIDTH = 800;
	int HEIGHT = 600;

	static void Clear(float r, float g, float b, float a)
	{
		GLCall(glClearColor(r, g, b, a));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	static void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
	{
		shader.Bind();
		va.Bind();
		ib.Bind();
		GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
	}

	static void DrawRubiks(const Cube& cube)
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
			glm::mat4 proj = glm::perspective(40.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 1.0f, 150.0f);
			glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -1));
			glm::mat4 model = glm::mat4(1.0f);
			//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

			glm::mat4 mvp = proj * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			shader.SetUniform4f("u_Color", 0.0f, 0.0f, 0.0f, 1.0f);
			Draw(va, ib, shader);
		}

		{
			glm::mat4 proj = glm::perspective(40.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 1.0f, 150.0f);
			glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -1));
			glm::mat4 model = glm::mat4(1.0f);
			//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			model = glm::translate(model, glm::vec3(0.1f, 0, 0));

			glm::mat4 mvp = proj * view * model;
			shader.Bind();
			shader.SetUniformMat4f("u_MVP", mvp);
			shader.SetUniform4f("u_Color", 0.0f, 0.0f, 0.0f, 1.0f);
			Draw(va, ib, shader);
		}

		
	}
}
