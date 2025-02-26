/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Renderer
*/

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Sdf.hpp"

void sdf::Renderer::loadShaders(void)
{
    _shaders.insert({"Sprite", sdf::Shader("Shader/Sprite/vertex.glsl",
        "Shader/Sprite/fragment.glsl")});
}

sdf::Renderer::Renderer(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // This two lines sets the verion
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // of openGL to 4.6 (latest)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window.reset(new Window);
    loadShaders();
    glEnable(GL_DEPTH_TEST);
}

sdf::Renderer::~Renderer(void)
{
    glfwTerminate();
}

bool sdf::Renderer::shouldClose(void)
{
    return glfwWindowShouldClose(_window->get());
}

void sdf::Renderer::clear(glm::vec4 color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void sdf::Renderer::swapBuffers(void)
{
    glfwSwapBuffers(_window->get());
}

void sdf::Renderer::pollEvent(void)
{
    glfwPollEvents();
}

GLFWwindow *sdf::Renderer::getWindow(void)
{
    return _window->get();
}

sdf::Shader &sdf::Renderer::getShader(const std::string &key)
{
    return _shaders.at(key);
}
