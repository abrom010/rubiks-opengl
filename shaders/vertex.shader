#version 330 core

layout(location = 0) in vec3 position;

out vec4 vertexColor;

uniform mat4 u_MVP;

void main()
{
    float scale = 0.1;
    gl_Position = u_MVP * vec4(scale, scale, scale, 1.0) * vec4(position, 1.0);
    vertexColor = vec4(1.0, 1.0, 1.0, 1.0);
}