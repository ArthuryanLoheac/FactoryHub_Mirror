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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window.reset(new Window);
    loadShaders();
}

sdf::Renderer::~Renderer(void)
{
    glfwTerminate();
}

bool sdf::Renderer::shouldClose(void)
{
    return glfwWindowShouldClose(_window->get());
}

void sdf::Renderer::clear(void)
{
    glClearColor(0.2f, 0.8f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void sdf::Renderer::draw(void)
{
    glUseProgram(_shaders.at("Sprite").use());
    for (sdf::Sprite &sprite : _sprites)
        sprite.draw();
    glfwSwapBuffers(_window->get());
}

void sdf::Renderer::pollEvent(void)
{
    glfwPollEvents();
}


void sdf::Renderer::addSprite(sdf::Sprite &sprite)
{
    _sprites.push_back(sprite);
}

unsigned int sdf::Renderer::getShader(const std::string &key)
{
    return _shaders.at(key).use();
}

GLFWwindow *sdf::Renderer::getWindow(void)
{
    return _window->get();
}
