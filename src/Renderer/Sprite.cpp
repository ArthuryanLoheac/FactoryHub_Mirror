/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Sprite
*/

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Sprite.hpp"

sdf::Sprite::Sprite(const glm::vec3 &position, sdf::Texture &texture,
    float direction)
    : _position(position), _size(1, 1), _texture(texture), _direction(direction), _isUI(false)
{
    // Starting vertices for a `square` sprite
    // A vertice is a point in space, here, I ignore the third dimension
    float vertices[] = {
        // positions    // texture coords
        -0.5f, -0.5f,   0.0f, 0.0f, // Bottom-Left
        -0.5f,  0.5f,   1.0f, 0.0f, // Top-Left
         0.5f,  0.5f,   1.0f, 1.0f, // Top-Right
         0.5f, -0.5f,   0.0f, 1.0f, // Bottom-Right
    };

    unsigned int indices[] = {
        0, 1, 2,    // First triangle
        2, 3, 0,    // Second triangle
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

    // Setup the buffer layout
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
        4 * sizeof(float), (void *)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
        4 * sizeof(float), (void *)(6 * sizeof(float)));
    // Finally, I tell openGL that the first shader of the render pipeline (fragment shader)
    // to sent the vertices by group of two to him.
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
}

void sdf::Sprite::draw(sdf::Renderer &renderer)
{
    int width, height;
    glfwGetWindowSize(renderer.getWindow(), &width, &height);
    // Bind shader
    renderer.getShader("Sprite").use();

    // Send the texture to the shader
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture.get());
    renderer.getShader("Sprite").set("ourTexture", 0);

    // Define matrices used to correctly position the sprites
    glm::mat4 model = glm::mat4(1.0f);
    if (_isUI)
        model = glm::translate(model, glm::vec3(_position.x + _size.x * 0.5f, _position.y + _size.y * 0.5f, _position.z));
    else
        model = glm::translate(model, _position);
    model = glm::rotate(model, glm::radians(_direction), glm::vec3(0.0f, 0.0f, 1.0f));
    if (_isUI)
        model = glm::scale(model, glm::vec3(-_size, 1.0f));
    else
        model = glm::scale(model, glm::vec3(_size, 1.0f));

    glm::mat4 view;
    if (_isUI)
        view = glm::mat4(1.0f);
    else
        view = renderer.getCamera().getTransformationMatrix();

    glm::mat4 projection;
    if (_isUI)
        projection = glm::ortho(
            0.0f, static_cast<float>(width),    // Left,    Right
            static_cast<float>(height), 0.0f,   // Bottom,  Top
            -100.0f, 10.0f                      // Near,    Far
        );
    else
        projection = glm::ortho(
            static_cast<float>(width / -100), static_cast<float>(width / 100),      // Left,    Right
            static_cast<float>(height / -100), static_cast<float>(height / 100),    // Bottom,  Top
            -100.0f, 10.0f                                                          // Near,    Far
        );
    // Send them to the shader
    renderer.getShader("Sprite").set("model", model);
    renderer.getShader("Sprite").set("view", view);
    renderer.getShader("Sprite").set("projection", projection);

    // Bind the VAO to restore all of the configuration done during the creation of the sprite
    glBindVertexArray(_VAO);
    // We draw 6 vertices as triangles
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // Unbind VAO to avoid annoying errors
    glBindVertexArray(0);
}

void sdf::Sprite::setPosition(const glm::vec2 &position)
{
    _position = {position.x, position.y, _position.z};
}

void sdf::Sprite::setSize(const glm::vec2 &size)
{
    _size = size;
}

void sdf::Sprite::setLayer(float layer)
{
    _position = {_position.x, _position.y, layer};
}

void sdf::Sprite::setDirection(float direction)
{
    _direction = direction;
}

unsigned int sdf::Sprite::getTexture(void)
{
    return _texture.get();
}
