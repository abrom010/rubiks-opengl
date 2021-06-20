#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Renderer.hpp"

class Window
{
private:
	GLFWwindow* glfwWindow;
public:
	Window(int width, int height, const char* title);
	~Window();

	bool ShouldCloseWindow();
	void ProcessInput(Renderer& renderer);
	void Update();
};