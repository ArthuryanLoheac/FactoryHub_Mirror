/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Window
*/

#include <iostream>
#include "Error.hpp"
#include "Window.hpp"

sdf::Window::Window(void)
    : _width(1080), _height(720)
{
    _window = glfwCreateWindow(_width, _height, "FactoryHUB", NULL, NULL);
    if (_window == NULL)
        throw sdf::Error("sdf::Window::Window: Failed to create glfwWindow");
    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw sdf::Error("sdf::Window::Window: Failed to initialize GLAD");

    glViewport(0, 0, _width, _height);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

GLFWwindow *sdf::Window::get(void)
{
    return _window;
}
