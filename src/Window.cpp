#include "Window.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "DebugOpenGL.hpp"


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (this->glfwWindow == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwSetWindowShouldClose(this->glfwWindow, true);
	}
	glfwMakeContextCurrent(this->glfwWindow);
	glfwSetFramebufferSizeCallback(this->glfwWindow, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwSetWindowShouldClose(this->glfwWindow, true);
	}

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	GLCall(glEnable(GL_DEPTH_TEST))
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::ShouldCloseWindow()
{
	return glfwWindowShouldClose(this->glfwWindow);
}

void Window::ProcessInput(Renderer& renderer)
{
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(this->glfwWindow, true);
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_LEFT) == GLFW_PRESS)
		renderer.horizontalRotation += 0.1f;
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_RIGHT) == GLFW_PRESS)
		renderer.horizontalRotation += -0.1f;
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_UP) == GLFW_PRESS)
		renderer.verticalRotation += 0.1f;
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_DOWN) == GLFW_PRESS)
		renderer.verticalRotation += -0.1f;
		
}

void Window::Update()
{
	glfwSwapBuffers(this->glfwWindow);
	glfwPollEvents();
}