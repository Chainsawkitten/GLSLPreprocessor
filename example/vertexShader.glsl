/*
Example vertex shader (using code from library.glsl).
*/
#version 400

#include "library.glsl"

void main() {
    vec3 a = vec3(0.0, 0.0, 0.0);
    vec3 b = vec3(1.0, 0.0, 0.5);
    
    gl_Position = add(a, b);
}
