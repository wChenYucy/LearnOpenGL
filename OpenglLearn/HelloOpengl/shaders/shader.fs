#version 330 core
out vec4 FragColor;

in vec3 ourColor; // 从顶点着色器传来的输入变量（名称相同、类型相同）
uniform float steptime;
int count = 0;
vec3 a = vec3(1.0f, 0.0f, 0.0f);
vec3 b = vec3(0.0f, 1.0f, 0.0f);
vec3 c = vec3(0.0f, 0.0f, 1.0f);

void main()
{

    if(ourColor == a)
        count = 0;

    FragColor = vec4(color,1.0f);
}