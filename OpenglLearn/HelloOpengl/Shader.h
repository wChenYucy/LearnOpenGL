//
// Created by chenyu on 2022/11/2.
//

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


#include <string>

class Shader {
public:
    explicit Shader(std::string_view file_path);

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    Shader(Shader&& other) noexcept = default;
    Shader& operator=(Shader&& other) noexcept = default;

    ~Shader();

    constexpr unsigned get_id() const noexcept { return id_; }

protected:
    unsigned id_;
    std::string source_;
};

class VertexShader: public Shader {
public:
    explicit VertexShader(std::string_view file_path);
};

class FragmentShader: public Shader {
public:
    explicit FragmentShader(std::string_view file_path);
};

class ShaderProgram {
public:
    ShaderProgram(std::string_view vertex_shader, std::string_view fragment_shader);

    ~ShaderProgram();

    void use() const noexcept;

    void set_uniform(std::string_view name, bool value) const noexcept;
    void set_uniform(std::string_view name, int value) const noexcept;
    void set_uniform(std::string_view name, float value) const noexcept;
    void set_uniform(std::string_view name, float value1,float value2,float value3,float value4) const noexcept;

private:
    unsigned id_;
};


#endif //SHADER_H
