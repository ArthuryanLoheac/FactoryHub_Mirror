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
#include "Sprite.hpp"
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
            void draw(void);
            void pollEvent(void);

            void addSprite(sdf::Sprite &sprite);

            unsigned int getShader(const std::string &key);
            GLFWwindow *getWindow(void);
        private:
            std::unique_ptr<sdf::Window> _window;
            std::vector<sdf::Sprite> _sprites;
            std::unordered_map<std::string, sdf::Shader> _shaders;

            void loadShaders(void);
    };
}
