/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** BuilderManager
*/
#include "BuilderManager.hpp"
#include "Tapis.hpp"
#include "Base.hpp"

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
    updateBuildKeys(window, map);
    updateDestroyKeys(window, map);
    updateRotateKeys(window, map);
    updateCancelKeys(window, map);
    for (int key : _keys)
        _lastKeyStates[key] = updateLastKeyState(key, window, _lastKeyStates[key]);
    for (int key : _mouseKeys)
        _lastKeyStates[key] = updateLastMouseState(key, window, _lastKeyStates[key]);
    updateSprite(window);
}

void BuilderManager::updateBuildKeys(GLFWwindow *window, MapGrid &map)
{
    if (isKeyClicked(window, GLFW_KEY_B, _lastKeyStates[GLFW_KEY_B])) {
        if (_canCancel == false && _isBuilding == BUILD)
            return;
        set_isBuilding((_isBuilding == BUILD) ? NONE : BUILD);
    }
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_1, _lastKeyStates[GLFW_MOUSE_BUTTON_1]) && _isBuilding == BUILD){
        buildBlock(window, map);
        if (_canCancel == false) {
            set_isBuilding(NONE);
            _canCancel = true;
            blockBuilding = std::make_shared<Tapis>();
        }
    }
}

void BuilderManager::updateDestroyKeys(GLFWwindow *window, MapGrid &map)
{
    if (isKeyClicked(window, GLFW_KEY_V, _lastKeyStates[GLFW_KEY_V]))
        set_isBuilding((_isBuilding == DESTROY) ? NONE : DESTROY);
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_1, _lastKeyStates[GLFW_MOUSE_BUTTON_1]) && _isBuilding == DESTROY)
        destroyBlock(window, map);
}

void BuilderManager::updateRotateKeys(GLFWwindow *window, MapGrid &map)
{
    if (isKeyClicked(window, GLFW_KEY_R, _lastKeyStates[GLFW_KEY_R]) && _isBuilding == BUILD) {
        _direction = (Direction)((_direction + 3) % 4);
        _spriteBuild->setDirection(_direction * 90);
    }
}

void BuilderManager::updateCancelKeys(GLFWwindow *window, MapGrid &map)
{
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_2, _lastKeyStates[GLFW_MOUSE_BUTTON_2])
        && _isBuilding != NONE) {
        if (_canCancel == false && _isBuilding == BUILD)
            return;
        set_isBuilding(NONE);
    }
}

void BuilderManager::updateSprite(GLFWwindow *window)
{
    if (_isBuilding == BUILD)
        _spriteBuild->setPosition(glm::vec3(getMousePos(window), 0.0f));
    if (_isBuilding == DESTROY)
        _spriteDestroy->setPosition(glm::vec3(getMousePos(window), 0.0f));
}

void BuilderManager::setCanCancel(bool canCancel)
{
    _canCancel = canCancel;
}

BuilderManager::BuilderManager()
{
    _keys = {GLFW_KEY_B, GLFW_KEY_V, GLFW_KEY_R};
    _mouseKeys = {GLFW_MOUSE_BUTTON_1, GLFW_MOUSE_BUTTON_2};
    if (instance == nullptr)
        instance = this;
    _spriteBuild = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("BuildGhost"), 0.0f);
    _spriteDestroy = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("DestroyGhost"), 0.0f);
    for (int key : _keys)
        _lastKeyStates[key] = GLFW_RELEASE;
    for (int key : _mouseKeys)
        _lastKeyStates[key] = GLFW_RELEASE;
    blockBuilding = std::make_shared<Tapis>();
}

bool BuilderManager::get_isBuilding() const
{
    return _isBuilding;
}

void BuilderManager::set_isBuilding(typeBuild isBuilding)
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

void BuilderManager::destroyBlock(GLFWwindow *window, MapGrid &map)
{
    glm::vec2 pos = getMousePos(window);
    std::vector<std::shared_ptr<IBlock>> blocks;

    try {
        blocks = map.getAllBlocksAtPos(pos.x, pos.y);
        if (blocks.size() == 0 || dynamic_cast<ABuilds *>(blocks[blocks.size() - 1].get()) == nullptr)
            return;
        if (dynamic_cast<Base *>(blocks[blocks.size() - 1].get()) != nullptr)
            return;
        map.deleteBlock(pos.x, pos.y, blocks.size() - 1);
    } catch (std::exception &e) {}
}

void BuilderManager::draw(sdf::Renderer &renderer)
{
    if (_isBuilding == BUILD)
        _spriteBuild->draw(renderer);
    if (_isBuilding == DESTROY)
        _spriteDestroy->draw(renderer);
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
    if (dynamic_cast<Base *>(blockBuilding.get()))
        return std::make_shared<Base>();
    return blockBuilding;
}

void BuilderManager::setBlockBuilding(std::shared_ptr<IBlock> block, bool canCancel)
{
    blockBuilding = block;
    _canCancel = canCancel;
}