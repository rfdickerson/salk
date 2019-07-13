#version 330 core

uniform mat4 MVPMatrix;

layout(location = 0) in vec3 VertexPosition;

void main() {

    gl_Position = MVPMatrix * vec4(VertexPosition, 1);

}
