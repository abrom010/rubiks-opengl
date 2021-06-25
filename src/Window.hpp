#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Renderer.hpp"

class Window
{
private:
	GLFWwindow* glfwWindow;
	float lastCursorX, lastCursorY;
	bool isDragging, isKeyPressed;
	bool w, y, g, b, r, o;
	int width, height;
	Cube& cube;
public:
	Window(int width, int height, const char* title, Cube& cube);
	~Window();

	bool ShouldCloseWindow();
	void ProcessInput(Renderer& renderer);
	void Update();
};