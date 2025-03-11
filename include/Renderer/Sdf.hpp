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
    struct TextureData {
        unsigned char *data;
        int width;
        int height;
        int channels;
    };
    class Renderer
    {
        public:
            Renderer(bool debug = false);
            ~Renderer(void);

            bool shouldClose(void);
            void clear(glm::vec4 color);
            void swapBuffers(void);
            void pollEvent(MapGrid &map);

            GLFWwindow *getWindow(void);
            sdf::Shader &getShader(const std::string &key);
            sdf::Camera &getCamera(void);
            double getDeltaTime(void);
            void resetDeltaTime(void);

            static void scroll_callback(GLFWwindow* window,
                double xoffset, double yoffset);
            void createTextAtlas(void);

            void log(const std::string &msg) const;
            void setDebug(bool state);
        private:
            bool _debug;
            std::unique_ptr<sdf::Window> _window;
            std::unordered_map<std::string, sdf::Shader> _shaders;
            sdf::Camera _camera;

            static Renderer *_instance;

            double _lastFrame;
            double _deltaTime;

            glm::ivec2 _textAtlasSize;
            std::unique_ptr<unsigned char> _atlasData;
            std::unordered_map<std::string, glm::vec2> _texturesUVs;

            void loadShaders(void);
            struct sdf::TextureData loadTexture(const std::string &path);
            void loadTexturesInAtlas(const std::vector<std::string> &texturesFiles);
    };
}
