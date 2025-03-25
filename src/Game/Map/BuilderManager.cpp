/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** BuilderManager
*/
#include "BuilderManager.hpp"
#include "Tapis.hpp"
#include "MinerT1.hpp"
#include "Base.hpp"
#include "AVein.hpp"
#include "Advanced_Assembly_Workshop.hpp"
#include "Advanced_Smelter.hpp"
#include "Assembly_Workshop.hpp"
#include "Capacitor_Factory.hpp"
#include "Chemical_Plant.hpp"
#include "Cutting_Machine.hpp"
#include "Foundry.hpp"
#include "High_Voltage_Generator.hpp"
#include "Molding_Workshop.hpp"
#include "Nuclear_Refinery.hpp"
#include "Smelter.hpp"
#include "Wiring_Factory.hpp"

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
        if (_isBase == true && _isBuilding == BUILD)
            return;
        set_isBuilding((_isBuilding == BUILD) ? NONE : BUILD);
    }
    if (isKeyClicked(window, GLFW_KEY_T, _lastKeyStates[GLFW_KEY_T]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Tapis>();
    }
    if (isKeyClicked(window, GLFW_KEY_M, _lastKeyStates[GLFW_KEY_M]) && !_isBase){
        _placementType = VEIN_ONLY;
        blockBuilding = std::make_shared<MinerT1>();
    }
    if (isKeyClicked(window, GLFW_KEY_E, _lastKeyStates[GLFW_KEY_E]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Smelter>();
    }
    if (isKeyClicked(window, GLFW_KEY_Y, _lastKeyStates[GLFW_KEY_Y]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Advanced_Smelter>();
    }
    if (isKeyClicked(window, GLFW_KEY_U, _lastKeyStates[GLFW_KEY_U]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Foundry>();
    }
    if (isKeyClicked(window, GLFW_KEY_I, _lastKeyStates[GLFW_KEY_I]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Chemical_Plant>();
    }
    if (isKeyClicked(window, GLFW_KEY_O, _lastKeyStates[GLFW_KEY_O]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Molding_Workshop>();
    }
    if (isKeyClicked(window, GLFW_KEY_P, _lastKeyStates[GLFW_KEY_P]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Cutting_Machine>();
    }
    if (isKeyClicked(window, GLFW_KEY_F, _lastKeyStates[GLFW_KEY_F]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Assembly_Workshop>();
    }
    if (isKeyClicked(window, GLFW_KEY_G, _lastKeyStates[GLFW_KEY_G]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Advanced_Assembly_Workshop>();
    }
    if (isKeyClicked(window, GLFW_KEY_H, _lastKeyStates[GLFW_KEY_H]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Capacitor_Factory>();
    }
    if (isKeyClicked(window, GLFW_KEY_J, _lastKeyStates[GLFW_KEY_J]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<High_Voltage_Generator>();
    }
    if (isKeyClicked(window, GLFW_KEY_K, _lastKeyStates[GLFW_KEY_K]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Wiring_Factory>();
    }
    if (isKeyClicked(window, GLFW_KEY_L, _lastKeyStates[GLFW_KEY_L]) && !_isBase){
        _placementType = FREE;
        blockBuilding = std::make_shared<Nuclear_Refinery>();
    }
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_1, _lastKeyStates[GLFW_MOUSE_BUTTON_1]) && _isBuilding == BUILD){
        if (_placementType == VEIN_ONLY)
            buildBlockVein(window, map);
        else
            buildBlockFree(window, map);
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
        _direction = (Direction)((_direction + 1) % 4);
        _spriteBuild->setDirection(_direction * 90);
    }
}

void BuilderManager::updateCancelKeys(GLFWwindow *window, MapGrid &map)
{
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_2, _lastKeyStates[GLFW_MOUSE_BUTTON_2])
        && _isBuilding != NONE) {
        if (_isBase == true && _isBuilding == BUILD)
            return;
        set_isBuilding(NONE);
    }
}

void BuilderManager::updateSprite(GLFWwindow *window)
{
    if (_isBuilding == BUILD)
        _spriteBuild->setPosition(glm::vec2(getMousePos(window)));
    if (_isBuilding == DESTROY)
        _spriteDestroy->setPosition(glm::vec2(getMousePos(window)));
}

void BuilderManager::setIsBase(bool isBase)
{
    _isBase = isBase;
}

BuilderManager::BuilderManager()
{
    _keys = {GLFW_KEY_B, GLFW_KEY_V, GLFW_KEY_E, GLFW_KEY_T, GLFW_KEY_M,
        GLFW_KEY_R, GLFW_KEY_Y, GLFW_KEY_U, GLFW_KEY_I,
        GLFW_KEY_O, GLFW_KEY_P, GLFW_KEY_F, GLFW_KEY_G,
        GLFW_KEY_H, GLFW_KEY_J, GLFW_KEY_K, GLFW_KEY_L};
    _mouseKeys = {GLFW_MOUSE_BUTTON_1, GLFW_MOUSE_BUTTON_2};
    if (instance == nullptr)
        instance = this;
    _spriteBuild = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 80.0f),
        sdf::GetterTextures::instance->getTexture("BuildGhost"), 0.0f);
    _spriteDestroy = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 80.0f),
        sdf::GetterTextures::instance->getTexture("DestroyGhost"), 0.0f);
    for (int key : _keys)
        _lastKeyStates[key] = GLFW_RELEASE;
    for (int key : _mouseKeys)
        _lastKeyStates[key] = GLFW_RELEASE;
    blockBuilding = std::make_shared<Tapis>();
    _placementType = FREE;
}

bool BuilderManager::get_isBuilding() const
{
    return _isBuilding;
}

void BuilderManager::set_isBuilding(typeBuild isBuilding)
{
    _isBuilding = isBuilding;
    _direction = Direction::UP;
    _spriteBuild->setDirection(_direction * 90);
}

void BuilderManager::BuildBlock(glm::vec2 pos, MapGrid &map)
{
    std::shared_ptr<IBlock> block = getCopyBlockBuilding();
    std::vector<std::pair<std::string, int>> cost;

    ABuilds *build = dynamic_cast<ABuilds *>(block.get());
    if (build != nullptr) {
        cost = build->getCost();
        for (auto &item : cost) {
            if (((Base *)(map.getBase()))->getItems()[item.first] < item.second){
                printf("Not enough %s\n", item.first.c_str());
                return;
            } else {
                ((Base *)(map.getBase()))->getItems()[item.first] -= item.second;
            }
        }
    }
    map.addBlock(block, pos.x, pos.y, _direction);
}

void BuilderManager::buildBlockFree(GLFWwindow *window, MapGrid &map)
{
    glm::vec2 pos = getMousePos(window);
    std::vector<std::shared_ptr<IBlock>> blocks;

    try {
        blocks = map.getAllBlocksAtPos(pos.x, pos.y);
        if (blocks.size() != 0 && blocks[blocks.size() - 1].get()->getIsConstructible() == false)
            return;
        BuildBlock(pos, map);
        if (_isBase == true) {
            set_isBuilding(NONE);
            _isBase = false;
            _placementType = FREE;
            blockBuilding = std::make_shared<Tapis>();
        }
    } catch (std::exception &e) {}
}

void BuilderManager::buildBlockVein(GLFWwindow *window, MapGrid &map)
{
    glm::vec2 pos = getMousePos(window);
    std::vector<std::shared_ptr<IBlock>> blocks;

    try {
        blocks = map.getAllBlocksAtPos(pos.x, pos.y);
        if (blocks.size() != 0 && blocks[blocks.size() - 1].get()->getIsConstructible() == false)
            return;
        if (blocks.size() == 0 || dynamic_cast<AVein *>(blocks[blocks.size() - 1].get()) == nullptr)
            return;
        BuildBlock(pos, map);
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
    pos.x = (int)(-vec.x + (xpos + 0.5f));
    pos.y = (int)(-vec.y + (ypos + 0.5f));
    return pos;
}

std::shared_ptr<IBlock> BuilderManager::getCopyBlockBuilding()
{
    if (dynamic_cast<Tapis *>(blockBuilding.get()))
        return std::make_shared<Tapis>();
    if (dynamic_cast<MinerT1 *>(blockBuilding.get()))
        return std::make_shared<MinerT1>();
    if (dynamic_cast<Base *>(blockBuilding.get()))
        return std::make_shared<Base>();
    if (dynamic_cast<Advanced_Assembly_Workshop *>(blockBuilding.get()))
        return std::make_shared<Advanced_Assembly_Workshop>();
    if (dynamic_cast<Advanced_Smelter *>(blockBuilding.get()))
        return std::make_shared<Advanced_Smelter>();
    if (dynamic_cast<Assembly_Workshop *>(blockBuilding.get()))
        return std::make_shared<Assembly_Workshop>();
    if (dynamic_cast<Capacitor_Factory *>(blockBuilding.get()))
        return std::make_shared<Capacitor_Factory>();
    if (dynamic_cast<Chemical_Plant *>(blockBuilding.get()))
        return std::make_shared<Chemical_Plant>();
    if (dynamic_cast<Cutting_Machine *>(blockBuilding.get()))
        return std::make_shared<Cutting_Machine>();
    if (dynamic_cast<Foundry *>(blockBuilding.get()))
        return std::make_shared<Foundry>();
    if (dynamic_cast<High_Voltage_Generator *>(blockBuilding.get()))
        return std::make_shared<High_Voltage_Generator>();
    if (dynamic_cast<Molding_Workshop *>(blockBuilding.get()))
        return std::make_shared<Molding_Workshop>();
    if (dynamic_cast<Nuclear_Refinery *>(blockBuilding.get()))
        return std::make_shared<Nuclear_Refinery>();
    if (dynamic_cast<Smelter *>(blockBuilding.get()))
        return std::make_shared<Smelter>();
    if (dynamic_cast<Wiring_Factory *>(blockBuilding.get()))
        return std::make_shared<Wiring_Factory>();
    return blockBuilding;
}

void BuilderManager::setBlockBuilding(std::shared_ptr<IBlock> block, bool isBase)
{
    blockBuilding = block;
    _isBase = isBase;
}