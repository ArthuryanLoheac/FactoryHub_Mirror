#include "BuilderManager.hpp"
#include <Tapis.hpp>
/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** BuilderManager
*/

BuilderManager *BuilderManager::instance = nullptr;

int BuilderManager::updateLastKeyState(int Key, GLFWwindow *window, int lastKey)
{
    if (glfwGetKey(window, Key) == GLFW_RELEASE)
        return GLFW_RELEASE;
    if (glfwGetKey(window, Key) == GLFW_PRESS)
        return GLFW_PRESS;
    return lastKey;
}

int BuilderManager::updateLastMouseState(int Key, GLFWwindow *window, int lastKey)
{
    if (glfwGetMouseButton(window, Key) == GLFW_RELEASE)
        return GLFW_RELEASE;
    if (glfwGetMouseButton(window, Key) == GLFW_PRESS)
        return GLFW_PRESS;
    return lastKey;
}

static bool isKeyClicked(GLFWwindow *window, int key, int lastKeyState)
{
    return glfwGetKey(window, key) == GLFW_RELEASE && lastKeyState == GLFW_PRESS;
}

static bool isMouseClicked(GLFWwindow *window, int key, int lastKeyState)
{
    return glfwGetMouseButton(window, key) == GLFW_RELEASE && lastKeyState == GLFW_PRESS;
}

void BuilderManager::updateKeyState(GLFWwindow *window, MapGrid &map)
{
    if (isKeyClicked(window, GLFW_KEY_B, _lastKeyStates[GLFW_KEY_B]))
        set_isBuilding(!get_isBuilding());
    if (isKeyClicked(window, GLFW_KEY_R, _lastKeyStates[GLFW_KEY_R])){
        _direction = (Direction)((_direction + 3) % 4);
        _sprite->setDirection(_direction * 90);
    }
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_2, _lastKeyStates[GLFW_MOUSE_BUTTON_2]) && _isBuilding)
        set_isBuilding(false);
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_1, _lastKeyStates[GLFW_MOUSE_BUTTON_1]) && _isBuilding)
        buildBlock(window, map);
    _lastKeyStates[GLFW_KEY_B] = updateLastKeyState(GLFW_KEY_B,
        window, _lastKeyStates[GLFW_KEY_B]);
    _lastKeyStates[GLFW_KEY_R] = updateLastKeyState(GLFW_KEY_R,
        window, _lastKeyStates[GLFW_KEY_R]);
    _lastKeyStates[GLFW_MOUSE_BUTTON_2] = updateLastMouseState(GLFW_MOUSE_BUTTON_2,
        window, _lastKeyStates[GLFW_MOUSE_BUTTON_2]);
    _lastKeyStates[GLFW_MOUSE_BUTTON_1] = updateLastMouseState(GLFW_MOUSE_BUTTON_1,
        window, _lastKeyStates[GLFW_MOUSE_BUTTON_1]);
    if (_isBuilding)
        _sprite->setPosition(glm::vec3(getMousePos(window), 0.0f));
}

BuilderManager::BuilderManager()
{
    if (instance == nullptr)
        instance = this;
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("BuildGhost"), 0.0f);
    _lastKeyStates[GLFW_KEY_B] = GLFW_RELEASE;
    _lastKeyStates[GLFW_KEY_R] = GLFW_RELEASE;
    _lastKeyStates[GLFW_MOUSE_BUTTON_2] = GLFW_RELEASE;
    _lastKeyStates[GLFW_MOUSE_BUTTON_1] = GLFW_RELEASE;
    blockBuilding = std::make_shared<Tapis>();
}

bool BuilderManager::get_isBuilding() const
{
    return _isBuilding;
}

void BuilderManager::set_isBuilding(bool isBuilding)
{
    _isBuilding = isBuilding;
    _direction = Direction::UP;
}

void BuilderManager::buildBlock(GLFWwindow *window, MapGrid &map)
{
    glm::vec2 pos = getMousePos(window);
    std::vector<std::shared_ptr<IBlock>> blocks;

    try {
        blocks = map.getAllBlocksAtPos(pos.x, pos.y);
        if (blocks.size() != 0 && blocks[blocks.size() - 1].get()->getIsConstructible() == false)
            return;
        std::shared_ptr<IBlock> block = getCopyBlockBuilding();
        map.addBlock(block, pos.x, pos.y, _direction);
    } catch (std::exception &e) {}
}

void BuilderManager::draw(sdf::Renderer &renderer)
{
    if (_isBuilding)
        _sprite->draw(renderer);
}

glm::vec2 BuilderManager::getMousePos(GLFWwindow *window)
{
    double xpos, ypos;
    int height, width;
    glm::vec2 pos;

    glfwGetCursorPos(window, &xpos, &ypos);
    glfwGetWindowSize(window, &width, &height);
    glm::vec2 vec = sdf::Camera::instance->getPosition();
    xpos = std::round((width / 2) - xpos) / (50 * sdf::Camera::instance->getZoom());
    ypos = std::round((height / 2) - ypos) / (50 * sdf::Camera::instance->getZoom());    
    pos.x = (int)(-vec.x - (xpos - 0.5f));
    pos.y = (int)(-vec.y + (ypos + 0.5f));
    return pos;
}

std::shared_ptr<IBlock> BuilderManager::getCopyBlockBuilding()
{
    if (dynamic_cast<Tapis *>(blockBuilding.get()))
        return std::make_shared<Tapis>();
    return blockBuilding;
}

void BuilderManager::setBlockBuilding(std::shared_ptr<IBlock> block)
{
    blockBuilding = block;
}