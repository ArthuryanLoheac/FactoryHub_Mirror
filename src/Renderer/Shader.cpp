/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Shader
*/

#include <fstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Error.hpp"
#include "Shader.hpp"

#include <iostream>

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

unsigned int sdf::Shader::use(void)
{
    return _shaderProgram;
}
