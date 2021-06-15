#include "Window.hpp"

int main()
{
	Window window(800, 600, "Rubiks");

	while (!window.ShouldCloseWindow())
	{
		window.ProcessInput();
		window.Update();
	}
}