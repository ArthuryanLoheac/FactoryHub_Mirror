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
#include "Camera.hpp"

class MapGrid;

namespace sdf {
    class Renderer
    {
        public:
            Renderer(void);
            ~Renderer(void);

            bool shouldClose(void);
            void clear(glm::vec4 color
                = glm::vec4(0.18f, 0.215f, 0.309f, 1.0f));
            void swapBuffers(void);
            void pollEvent(MapGrid &map);

            GLFWwindow *getWindow(void);
            sdf::Shader &getShader(const std::string &key);
            sdf::Camera &getCamera(void);
            double getDeltaTime(void);
            void resetDeltaTime(void);

            static void scroll_callback(GLFWwindow* window,
                double xoffset, double yoffset);
        private:
            std::unique_ptr<sdf::Window> _window;
            std::unordered_map<std::string, sdf::Shader> _shaders;
            sdf::Camera _camera;

            static Renderer *_instance;

            double _lastFrame;
            double _deltaTime;

            void loadShaders(void);
    };
}
