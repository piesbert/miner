#version 150

uniform mat4 camera;

in vec3 vert;
in vec2 vertTexCoord;

out vec2 fragTexCoord;

void main() {
        fragTexCoord = vertTexCoord;
        gl_Position = camera * vec4(vert, 1);
}
