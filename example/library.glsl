/*
Library providing functionality used by vertexShader.glsl.
*/

// Include ourselves to show recursive inclusion.
#include "library.glsl"

/// Add two vectors together.
/**
 * @param a First vector to add.
 * @param b Second vector to add.
 */
vec3 add(in vec3 a, in vec3 b) {
    return a + b;
}
