/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Shader
*/

#pragma once
#include <string>

namespace sdf
{
    class Shader
    {
        public:
            Shader(const std::string &vertexPath,
                const std::string &fragmentPath);

            void use(void);
        private:
            unsigned int _shaderProgram;
    };
}
