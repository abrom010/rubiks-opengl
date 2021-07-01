#version 330 core

layout(location = 0) in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec4 u_Color;

out vec4 vertexColor;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
	vertexColor = u_Color;
}