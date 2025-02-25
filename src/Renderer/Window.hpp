/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Windown
*/

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace sdf
{
    class Window
    {
        public:
            Window(void);

            GLFWwindow *get(void);

            const std::size_t _width;
            const std::size_t _height;
        private:
            GLFWwindow *_window;
    };
}
