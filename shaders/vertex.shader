#version 330 core

layout(location = 0) in vec3 position;

out vec4 vertexColor;

uniform mat4 u_MVP;
uniform vec4 u_Color;

void main()
{
    gl_Position = u_MVP * vec4(position, 1.0);
	vertexColor = u_Color;
}