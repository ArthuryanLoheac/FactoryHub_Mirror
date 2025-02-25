/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Texture
*/

#pragma once
#include <string>

namespace sdf
{
    class Texture
    {
        public:
            Texture(const std::string &path);
            ~Texture(void);

            unsigned int get(void);
        private:
            unsigned int _texture;
            int _width;
            int _height;
            int _nrChannels;
    };
}
