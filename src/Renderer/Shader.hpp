/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Shader
*/

#pragma once
#include <string>
#include <glm/glm.hpp>

namespace sdf
{
    class Shader
    {
        public:
            Shader(const std::string &vertexPath,
                const std::string &fragmentPath);

            void use(void);

            void set(const std::string &name, bool value) const;
            void set(const std::string &name, int value) const;
            void set(const std::string &name, float value) const;
            void set(const std::string &name, glm::vec2 value) const;
            void set(const std::string &name, glm::vec3 value) const;
            void set(const std::string &name, glm::vec4 value) const;
            void set(const std::string &name, glm::mat2 value) const;
            void set(const std::string &name, glm::mat3 value) const;
            void set(const std::string &name, glm::mat4 value) const;
        private:
            unsigned int _shaderProgram;
    };
}
