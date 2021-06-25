#include "Window.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "DebugOpenGL.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* title, Cube& cube)
	: lastCursorX(0), lastCursorY(0), isDragging(false), width(width), height(height), cube(cube), w(false), y(false), g(false), b(false), r(false), o(false)
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


	if (glfwGetKey(this->glfwWindow, GLFW_KEY_W) == GLFW_PRESS)
	{
		if (!w)
		{
			w = true;
			if (glfwGetKey(this->glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
				cube.rotateFace(cube.whiteFace, false);
			else
				cube.rotateFace(cube.whiteFace, true);
		}
			
	}
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_Y) == GLFW_PRESS)
	{
		if (!y)
		{
			y = true;
			if (glfwGetKey(this->glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
				cube.rotateFace(cube.yellowFace, false);
			else
				cube.rotateFace(cube.yellowFace, true);
		}
		
	}
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_G) == GLFW_PRESS)
	{
		if (!g)
		{
			g = true;
			if (glfwGetKey(this->glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
				cube.rotateFace(cube.greenFace, false);
			else
				cube.rotateFace(cube.greenFace, true);
		}
	}
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_B) == GLFW_PRESS)
	{
		if (!b)
		{
			b = true;
			if (glfwGetKey(this->glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
				cube.rotateFace(cube.blueFace, false);
			else
				cube.rotateFace(cube.blueFace, true);
		}
	}
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_R) == GLFW_PRESS)
	{
		if (!r)
		{
			r = true;
			if (glfwGetKey(this->glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
				cube.rotateFace(cube.redFace, false);
			else
				cube.rotateFace(cube.redFace, true);
		}
	}
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_O) == GLFW_PRESS)
	{
		if (!o)
		{
			o = true;
			if (glfwGetKey(this->glfwWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
				cube.rotateFace(cube.orangeFace, false);
			else
				cube.rotateFace(cube.orangeFace, true);
		}
	}

	if (glfwGetKey(this->glfwWindow, GLFW_KEY_W) == GLFW_RELEASE)
		w = false;
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_Y) == GLFW_RELEASE)
		y = false;
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_G) == GLFW_RELEASE)
		g = false;
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_B) == GLFW_RELEASE)
		b = false;
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_R) == GLFW_RELEASE)
		r = false;
	if (glfwGetKey(this->glfwWindow, GLFW_KEY_O) == GLFW_RELEASE)
		o = false;

	if (glfwGetMouseButton(this->glfwWindow, GLFW_MOUSE_BUTTON_LEFT == GLFW_PRESS))
	{
		if (!isDragging)
		{
			this->isDragging = true;
			double xpos, ypos;
			glfwGetCursorPos(this->glfwWindow, &xpos, &ypos);
			
			lastCursorX = xpos;
			lastCursorY = ypos;
		}
		else
		{
			double xpos, ypos;
			glfwGetCursorPos(this->glfwWindow, &xpos, &ypos);

			float normalizedLastX = -1.0 + 2.0 * lastCursorX / width;
			float normalizedLastY = 1.0 - 2.0 * lastCursorY / height;

			float normalizedCurrentX = -1.0 + 2.0 * xpos / width;
			float normalizedCurrentY = 1.0 - 2.0 * ypos / height;

			renderer.arcball.rotate(glm::vec2(normalizedLastX, normalizedLastY), glm::vec2(normalizedCurrentX, normalizedCurrentY));

			lastCursorX = xpos;
			lastCursorY = ypos;
		}
	}
	else
	{
		if (this->lastCursorX != 0 && this->lastCursorY != 0)
		{
			this->lastCursorX = 0;
			this->lastCursorY = 0;
			this->isDragging = false;
		}
	}
}

void Window::Update()
{
	glfwSwapBuffers(this->glfwWindow);
	glfwPollEvents();
}