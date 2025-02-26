/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Shader
*/

#include <fstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include "Error.hpp"
#include "Shader.hpp"

static std::string getShaderCode(const std::string &path)
{
    std::ifstream file(path);
    std::string content;

    if (!file.is_open())
        throw sdf::Error("sdf::Shader: Unable to open shader file '"
            + path + "'");
    file.seekg(std::ios::end);
    content.reserve(file.tellg());
    file.seekg(std::ios::beg);
    content.assign((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());
    return content;
}

/**
 * We have to compile all of the 'subShaders' before compiling our main shaderProgram
 * This functions reads the content of a file and then compiles the associated shader.
 */
static unsigned int compileShader(const std::string &path, unsigned int shaderType)
{
    unsigned int shader = glCreateShader(shaderType);
    std::string code = getShaderCode(path);
    const char *codeSource = code.c_str();
    int success;
    char infoLog[512];

    glShaderSource(shader, 1, &codeSource, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        throw sdf::Error("sdf::Shader: Unable to compile "
            + path + " : " + std::string(infoLog));
    }
    return shader;
}

sdf::Shader::Shader(const std::string &vertexPath,
    const std::string &fragmentPath)
{
    unsigned int vertexShader = compileShader(vertexPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = compileShader(fragmentPath, GL_FRAGMENT_SHADER);
    int success;

    // This command are the same as Linking .o files between them.
    _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, vertexShader);
    glAttachShader(_shaderProgram, fragmentShader);
    glLinkProgram(_shaderProgram);

    glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        int logLenght;
        glGetProgramiv(_shaderProgram, GL_INFO_LOG_LENGTH, &logLenght);
        char infoLog[logLenght];
        glGetProgramInfoLog(_shaderProgram, logLenght, NULL, infoLog);
        throw sdf::Error("sdf::Shader::Shader: Unable to compile the shaderProgram: "
         + std::string(infoLog));
    }
    // We don't need the compiled shaders anymore (they takes space in memory)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void sdf::Shader::use(void)
{
    return glUseProgram(_shaderProgram);
}

#pragma region Uniform setters

void sdf::Shader::set(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(_shaderProgram, name.c_str()), (int)value);
}

void sdf::Shader::set(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(_shaderProgram, name.c_str()), value);
}

void sdf::Shader::set(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(_shaderProgram, name.c_str()), value);
}

void sdf::Shader::set(const std::string &name, glm::vec2 value) const
{
    glUniform2f(glGetUniformLocation(_shaderProgram, name.c_str()),
        value.x, value.y);
}

void sdf::Shader::set(const std::string &name, glm::vec3 value) const
{
    glUniform3f(glGetUniformLocation(_shaderProgram, name.c_str()),
        value.x, value.y, value.z);
}

void sdf::Shader::set(const std::string &name, glm::vec4 value) const
{
    glUniform4f(glGetUniformLocation(_shaderProgram, name.c_str()),
        value.x, value.y, value.z, value.w);
}

void sdf::Shader::set(const std::string &name, glm::mat2 value) const
{
    glUniformMatrix2fv(glGetUniformLocation(_shaderProgram, name.c_str()),
        1, GL_FALSE, glm::value_ptr(value));
}

void sdf::Shader::set(const std::string &name, glm::mat3 value) const
{
    glUniformMatrix3fv(glGetUniformLocation(_shaderProgram, name.c_str()),
        1, GL_FALSE, glm::value_ptr(value));
}

void sdf::Shader::set(const std::string &name, glm::mat4 value) const
{
    glUniformMatrix4fv(glGetUniformLocation(_shaderProgram, name.c_str()),
        1, GL_FALSE, glm::value_ptr(value));
}

#pragma endregion Uniform setters
