#version 330 core

in vec4 vertexColor;
in vec3 fragPos;

out vec4 fragmentColor;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 normal;

void main()
{
	vec3 ambient = lightColor * 0.8f;
	
	vec3 lightDir = viewPos - fragPos;
	float diff = max(dot(lightDir, normal), 0.0);
	vec3 diffuse = lightColor * diff;

	/*vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(reflectDir, viewDir), 0.0), 32.0);
	vec3 specular = lightColor * spec;*/

    //fragmentColor = vec4((ambient + diffuse) * vertexColor, 1.0);
	fragmentColor = vec4(vertexColor);
}