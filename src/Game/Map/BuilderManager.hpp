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
        enum placementType {
            FREE,
            VEIN_ONLY,
        };
    private:
        bool _isBase = true;

        std::map<int, int> _lastKeyStates;
        typeBuild _isBuilding = NONE;
        std::shared_ptr<IBlock> blockBuilding;
        Direction _direction = Direction::UP;
        sdf::Sprite *_spriteBuild;
        sdf::Sprite *_spriteDestroy;

        std::vector<int> _keys;
        std::vector<int> _mouseKeys;

        placementType _placementType = FREE;
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

        void setBlockBuilding(std::shared_ptr<IBlock> block, bool isBase = false);
        void setIsBase(bool isBase);
        bool get_isBuilding() const;
        void set_isBuilding(typeBuild isBuilding);
        void buildBlockFree(GLFWwindow *window, MapGrid &map);
        void buildBlockVein(GLFWwindow *window, MapGrid &map);
        void BuildBlock(glm::vec2 pos, MapGrid &map);
        void destroyBlock(GLFWwindow *window, MapGrid &map);
        void draw(sdf::Renderer &renderer);
        glm::vec2 getMousePos(GLFWwindow *window);

        std::shared_ptr<IBlock> getCopyBlockBuilding();
};
