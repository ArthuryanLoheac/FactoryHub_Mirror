/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Renderer
*/

#include <iostream>
#include <filesystem>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_images.h>

#include "Sdf.hpp"
#include <MapGrid.hpp>

sdf::Renderer *sdf::Renderer::_instance = nullptr;

sdf::Renderer::Renderer(bool debug)
    : _lastFrame(0), _deltaTime(0), _debug(debug)
{
    _instance = this;
    log("Initializing GLFW");
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // This two lines sets the verion
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // of openGL to 4.6 (latest)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window.reset(new Window);
    log("Loading shaders");
    loadShaders();
    createTextAtlas();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND); // Enable transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

void sdf::Renderer::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (_instance)
        _instance->getCamera().setZoom(_instance->getCamera().getZoom() + (yoffset / 10));
}

void sdf::Renderer::pollEvent(MapGrid &map)
{
    double actualTime = glfwGetTime();
    _deltaTime = glfwGetTime() - _lastFrame;
    _lastFrame = glfwGetTime();

    glfwSetScrollCallback(_window->get(), scroll_callback);
    glfwPollEvents();
    if (glfwGetKey(_window->get(), GLFW_KEY_W) == GLFW_PRESS)
        _camera.move(sdf::Camera::Direction::UP, _deltaTime, map.getSizeX(), map.getSizeY());
    if (glfwGetKey(_window->get(), GLFW_KEY_S) == GLFW_PRESS)
        _camera.move(sdf::Camera::Direction::DOWN, _deltaTime, map.getSizeX(), map.getSizeY());
    if (glfwGetKey(_window->get(), GLFW_KEY_D) == GLFW_PRESS)
        _camera.move(sdf::Camera::Direction::RIGHT, _deltaTime, map.getSizeX(), map.getSizeY());
    if (glfwGetKey(_window->get(), GLFW_KEY_A) == GLFW_PRESS)
        _camera.move(sdf::Camera::Direction::LEFT, _deltaTime, map.getSizeX(), map.getSizeY());
}

#pragma region loaders

void sdf::Renderer::loadShaders(void)
{
    _shaders.insert({"Sprite", sdf::Shader("Shader/Sprite/vertex.glsl",
        "Shader/Sprite/fragment.glsl")});
}

struct sdf::TextureData sdf::Renderer::loadTexture(const std::string &path)
{
    struct sdf::TextureData tex;

    tex.data = stbi_load(
        path.c_str(), &tex.width, &tex.height, &tex.channels, 4);
    if (tex.data == nullptr)
        throw sdf::Error("SDF: Texture loader failed to load file:"
            " not found (" + path + ')');
    if (tex.channels != 4)
        throw sdf::Error("SDF: Texture loader failed to load file:"
            " wrong format (" + path + ')');
    return tex;
}

static void copyTexture(const unsigned char *src, glm::ivec2 srcPos,
    unsigned char *dest, glm::ivec2 destPos, glm::ivec2 size)
{
    int bytesPerPixels = 4;

    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            int srcIndex = ((y + srcPos.y) * size.y + (x + srcPos.x)) * bytesPerPixels;
            int destIndex = ((y + destPos.y) * size.y + (x + destPos.x)) * bytesPerPixels;

            dest[destIndex + 0] = src[srcIndex + 0];
            dest[destIndex + 1] = src[srcIndex + 1];
            dest[destIndex + 2] = src[srcIndex + 2];
            dest[destIndex + 3] = src[srcIndex + 3];
        }
    }
}

static std::string getTextureNameFromFilePath(const std::string &filepath)
{
    return filepath.substr(filepath.find("/") + 1,
        filepath.size() - filepath.find("/") - 5);
}

void sdf::Renderer::loadTexturesInAtlas(const std::vector<std::string> &texturesFiles)
{
    sdf::TextureData textureDataBuffer;
    std::string textureNameBuffer;
    std::size_t pos;

    log("Allocation space for texture atlas");
    _textAtlasSize = glm::ivec2(256 * 20 * 4, 256 * texturesFiles.size() * 4);
    _atlasData.reset(new unsigned char[_textAtlasSize.x * _textAtlasSize.y + 1]);
    _atlasData.get()[_textAtlasSize.x * _textAtlasSize.y] = '\0';
    log("Loading textures in texture atlas");
    for (const auto &texture: texturesFiles) {
        textureDataBuffer = loadTexture(texture);
        textureNameBuffer = getTextureNameFromFilePath(texture);
        _texturesUVs[textureNameBuffer] = glm::vec2(0, pos * 256);
        copyTexture(textureDataBuffer.data, glm::ivec2(0),
            _atlasData.get(), glm::ivec2(0, pos * 256), 
            glm::ivec2(textureDataBuffer.width, textureDataBuffer.height));
        log(std::string("\e[97m") + "Loaded "
            + std::string("\e[95m") + texture
            + std::string("\e[97m") + " with key "
            + std::string("\e[93m") + "'"
            + std::string("\e[94m") + textureNameBuffer
            + std::string("\e[93m") + "'" + std::string("\e[37m"));
        pos++;
    }
}

void sdf::Renderer::createTextAtlas(void)
{
    std::string spritesPath = "Assets";
    std::vector<std::string> texturesFiles;
    int pos = 0;

    log("Listing textures");
    for (const auto &entry : std::filesystem::directory_iterator(spritesPath)) {
        if (entry.is_regular_file()) {
            texturesFiles.push_back(entry.path());
            pos++;
        }
    }
    log(std::to_string((int)(pos)) + " textures found");
    loadTexturesInAtlas(texturesFiles);
}

#pragma endregion loaders

#pragma region getters

GLFWwindow *sdf::Renderer::getWindow(void)
{
    return _window->get();
}

sdf::Shader &sdf::Renderer::getShader(const std::string &key)
{
    return _shaders.at(key);
}

sdf::Camera &sdf::Renderer::getCamera(void)
{
    return _camera;
}

double sdf::Renderer::getDeltaTime(void)
{
    return _deltaTime;
}

void sdf::Renderer::resetDeltaTime(void)
{
    _deltaTime = 0;
    _lastFrame = glfwGetTime();
}

#pragma endregion getters

void sdf::Renderer::log(const std::string &msg) const
{
    char blue[] = "\e[94m";
    char white[] = "\e[39m";

    if (_debug)
        std::cout << blue << "[RENDERER]"
            << white << msg << std::endl;
}

void sdf::Renderer::setDebug(bool state)
{
    _debug = state;
}
