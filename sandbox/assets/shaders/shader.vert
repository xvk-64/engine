#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec2 aUV; // the color variable has attribute position 1
layout (location = 2) in vec3 aNormal; // the color variable has attribute position 1

out vec3 ourColor; // output a color to the fragment shader

uniform mat4 transform;
uniform mat4 viewProjection;

void main()
{
    gl_Position = viewProjection * transform * vec4(aPos, 1.0);
    ourColor = vec3(aUV, 0.0); // set ourColor to the input color we got from the vertex data
}