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
    // A vertice is a point in space, here, I ignore the third dimension
    float vertices[] = {
        -0.5f, -0.5f,   // Bottom-Left
        -0.5f,  0.5f,   // Top-Left
         0.5f,  0.5f,   // Top-Right
         0.5f, -0.5f,   // Bottom-Right
    };

    unsigned int indices[] = {
        0, 1, 2,    // First triangle
        0, 3, 2,    // Second triangle
    };

    glGenVertexArrays(1, &_VAO); // The VAO is used to save all of the state of openGL after all the incoming calls
    glGenBuffers(1, &_VBO);      // The VBO is a buffer used to send the vertices to the graphic card
    glGenBuffers(1, &_EBO);      // The EBO is contains the order in which to draw/connect the vertices

    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // We send the vertices inside the VBO

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // We send the indices inside the EBO

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    // Finally, I tell openGL that the first shader of the render pipeline (fragment shader)
    // to sent the vertices by group of two to him.
    glEnableVertexAttribArray(0);
}

void sdf::Sprite::draw(void)
{
    glBindVertexArray(_VAO); // We bind the VAO to restore all of the configuration done during the creation of the sprite
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // We draw 6 vertices as triangles
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
