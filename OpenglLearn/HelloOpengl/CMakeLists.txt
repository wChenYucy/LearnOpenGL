cmake_minimum_required(VERSION 3.21)
project(HelloOpengl)

set(CMAKE_CXX_STANDARD 11)

#引入glad头文件，将glad目录下的include文件夹引入工程，使其下的头文件能正确别识别
include_directories("/opt/glad/include")

#引入glfw头文件目录，将glfw目录下的include文件夹引入工程，使其下的头文件能正确识别
include_directories("/opt/homebrew/Cellar/glfw/3.3.8/include")

#引入glfw动态链接库目录，将glfw目录下的lib文件夹引入工程，使其下的动态链接库在构建时能正确识别
link_directories("/opt/homebrew/Cellar/glfw/3.3.8/lib")

#引入glad源代码，将glad目录下的src文件夹中的源代码glad.c加入构建
add_executable(HelloOpengl
        /opt/glad/src/glad.c
        main.cpp Shader.cpp Shader.h)

#将glfw的动态链接库文件libglfw.dylib与工程链接
target_link_libraries(HelloOpengl glfw)
