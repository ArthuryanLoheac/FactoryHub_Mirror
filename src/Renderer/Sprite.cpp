/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Sprite
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Sprite.hpp"
#include "Sdf.hpp"

#include <iostream>

sdf::Sprite::Sprite(const glm::vec2 &position, const glm::vec2 &size)
    : _position(position), _size(size), _VAO(0), _VBO(0)
{
    // Starting vertices for a `square` sprite
    float vertices[] = {
        -0.5f, -0.5f,   // Bottom-Left
        -0.5f,  0.5f,   // Top-Left
         0.5f,  0.5f,   // Top-Right
         0.5f, -0.5f,   // Bottom-Right
    };

    unsigned int indices[] = {
        0, 1, 2,
        0, 3, 2,
    };

    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);
    glGenBuffers(1, &_EBO);

    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
}

void sdf::Sprite::draw(void)
{
    glBindVertexArray(_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void sdf::Sprite::setPosition(const glm::vec2 &position)
{
    _position = position;
}

void sdf::Sprite::setSize(const glm::vec2 &size)
{
    _size = size;
}
