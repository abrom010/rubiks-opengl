#include "Window.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

#include "DebugOpenGL.hpp"

int main()
{
    Window window(800, 600, "Rubiks");

    VertexArray va;
    IndexBuffer ib;

    Shader shader;

    while (!window.ShouldCloseWindow())
    {
        window.ProcessInput();

        // render
        
        window.Update();
    }

}