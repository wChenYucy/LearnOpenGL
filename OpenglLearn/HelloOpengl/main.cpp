#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>
#include "Shader.h"

void framebuffer_size_callback(GLFWwindow* window,int width,int height);
void processInput(GLFWwindow * window);

int main()
{

    // 初始化glfw，并设置glfw基本参数
    // --------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif

    // glfw创建窗口
    GLFWwindow * mainWindow = glfwCreateWindow(800,600,"LearnOpenGL", nullptr, nullptr);
    if(mainWindow == nullptr){
        std::cout<< "GLFW创建窗口失败！"<<std::endl;
        return -1;
    }

    glfwMakeContextCurrent(mainWindow);
    glfwSetFramebufferSizeCallback(mainWindow,framebuffer_size_callback);



    //初始化glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "初始化GLAD失败！" << std::endl;
        return -1;
    }

    //glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    /****绘制三角形*****/
    //三角形顶点坐标
    float vertices[] = {
            // 位置                           // 颜色
            0.0f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
            -1.0f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
            -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
    };

    unsigned int VAO;
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);


    unsigned int VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    ShaderProgram ourShader("../shaders/shader.vs", "../shaders/shader.fs");

    /****绘制三角形******/

    // 渲染循环
    while(!glfwWindowShouldClose(mainWindow)){

        // 处理输入指令
        processInput(mainWindow);

        //处理渲染命令
        float timeValue = glfwGetTime();
        float time = (sin(timeValue) / 2.0f)+0.5f;
        ourShader.set_uniform("time",time);
        float halftime = sin(timeValue + (float)M_PI/2.0f) /2.0f;
        ourShader.set_uniform("halftime",halftime);
        float steptime = abs(sin(timeValue));
        ourShader.set_uniform("steptime",halftime);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ourShader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(mainWindow);
        glfwPollEvents();
    }
    // 关闭窗口
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window,int width,int height){
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow * window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(window, true);
    }
}