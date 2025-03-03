/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** GetterTextures
*/

#pragma once
#include <map>
#include "Texture.hpp"
#include "MapGrid.hpp"

namespace sdf {
    class GetterTextures
    {
        public:
            static GetterTextures *instance;

            GetterTextures();
            sdf::Texture &getTexture(const std::string &name);
            std::map<std::string, sdf::Texture *> textures;
        protected:
        private:
    };
}
