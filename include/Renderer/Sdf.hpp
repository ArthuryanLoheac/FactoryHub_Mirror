/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Sdf
*/

#pragma once
#include <string>
#include <memory>
#include "Error.hpp"
#include "Window.hpp"
#include "Shader.hpp"

namespace sdf {
    class Renderer
    {
        public:
            Renderer(void);
            ~Renderer(void);

            bool shouldClose(void);
            void clear(void);
            void swapBuffers(void);
            void pollEvent(void);

            GLFWwindow *getWindow(void);
            sdf::Shader &getShader(const std::string &key);
        private:
            std::unique_ptr<sdf::Window> _window;
            std::unordered_map<std::string, sdf::Shader> _shaders;

            void loadShaders(void);
    };
}
