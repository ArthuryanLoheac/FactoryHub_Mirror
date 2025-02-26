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
            void clear(glm::vec4 color
                = glm::vec4(0.2f, 0.4f, 0.6f, 1.0f));
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
