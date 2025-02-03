#version 330 core
layout (location = 0) in vec3 aPos;         // Vertex position
layout (location = 1) in vec2 aTexCoords;     // Texture coordinates
layout (location = 2) in vec3 aNormal;        // Normal vector
layout (location = 3) in vec3 aTangent;       // Tangent vector

out vec2 TexCoords;
out vec3 FragPos;
out mat3 TBN;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // Transform vertex position to world space
    FragPos = vec3(model * vec4(aPos, 1.0));
    TexCoords = aTexCoords;

    // Calculate TBN matrix
    vec3 T = normalize(mat3(model) * aTangent);
    vec3 N = normalize(mat3(model) * aNormal);
    // Ensure T is orthogonal to N
    T = normalize(T - dot(T, N) * N);
    vec3 B = cross(N, T);
    TBN = mat3(T, B, N);

    // Output final position
    gl_Position = projection * view * vec4(FragPos, 1.0);
}
