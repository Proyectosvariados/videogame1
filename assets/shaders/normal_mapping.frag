#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 FragPos;
in mat3 TBN;

uniform sampler2D diffuseMap;
uniform sampler2D normalMap;

uniform vec3 lightPos;   // Position of the light source in world space
uniform vec3 viewPos;    // Position of the camera/viewer in world space

void main()
{
    // Sample the normal map and transform the normal from [0,1] to [-1,1]
    vec3 normal = texture(normalMap, TexCoords).rgb;
    normal = normalize(normal * 2.0 - 1.0);
    normal = normalize(TBN * normal);

    // Sample diffuse color
    vec3 color = texture(diffuseMap, TexCoords).rgb;
    
    // Calculate diffuse lighting
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * color;

    // Calculate specular component
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    vec3 specular = vec3(0.2) * spec;

    FragColor = vec4(diffuse + specular, 1.0);
}
