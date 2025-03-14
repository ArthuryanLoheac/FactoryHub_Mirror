/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** BuilderManager
*/

#pragma once
#include "ABuilds.hpp"
#include "MapGrid.hpp"

class BuilderManager
{
    public:
        enum typeBuild {
            NONE,
            BUILD,
            DESTROY
        };
    private:
        bool _canCancel = true;

        std::map<int, int> _lastKeyStates;
        typeBuild _isBuilding = NONE;
        std::shared_ptr<IBlock> blockBuilding;
        Direction _direction = Direction::UP;
        sdf::Sprite *_spriteBuild;
        sdf::Sprite *_spriteDestroy;

        std::vector<int> _keys;
        std::vector<int> _mouseKeys;

    public:
        static BuilderManager *instance;
        BuilderManager();

        int updateLastKeyState(int Key, GLFWwindow *window, int lastKey);
        int updateLastMouseState(int Key, GLFWwindow *window, int lastKey);
        void updateKeyState(GLFWwindow *window, MapGrid &map);

        void updateSprite(GLFWwindow *window);
        void updateBuildKeys(GLFWwindow *window, MapGrid &map);
        void updateDestroyKeys(GLFWwindow *window, MapGrid &map);
        void updateRotateKeys(GLFWwindow *window, MapGrid &map);
        void updateCancelKeys(GLFWwindow *window, MapGrid &map);

        void setBlockBuilding(std::shared_ptr<IBlock> block, bool canCancel = true);
        void setCanCancel(bool canCancel);
        bool get_isBuilding() const;
        void set_isBuilding(typeBuild isBuilding);
        void buildBlock(GLFWwindow *window, MapGrid &map);
        void destroyBlock(GLFWwindow *window, MapGrid &map);
        void draw(sdf::Renderer &renderer);
        glm::vec2 getMousePos(GLFWwindow *window);

        std::shared_ptr<IBlock> getCopyBlockBuilding();
};
