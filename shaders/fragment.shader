#version 330 core

in vec4 vertexColor;
//in vec3 fragPos;

out vec4 fragmentColor;

//uniform vec3 lightColor;
//uniform vec3 lightPos;
//uniform vec3 viewPos;

void main()
{
	/*float ambientStrength = 0.1f;
	vec3 ambient = ambientStrength * lightColor;
	
	vec3 norm;
	if (fragPos.x > fragPos.y && fragPos.x > fragPos.z)
	{
		norm = normalize(vec3(0, fragPos.y, fragPos.z) - fragPos);
	}
	else if (fragPos.y > fragPos.x && fragPos.y > fragPos.z)
	{
		norm = normalize(vec3(fragPos.x, 0, fragPos.z) - fragPos);
	}
	else
	{
		norm = normalize(vec3(fragPos.x, fragPos.y, 0) - fragPos);
	}

	vec3 lightDir = normalize(lightPos - fragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = lightColor * diff;

	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
	vec3 specular = lightColor * spec;*/

	fragmentColor = vec4(vertexColor.xyz, vertexColor.w);
}