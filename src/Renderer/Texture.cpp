/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Texture
*/

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_images.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include "Texture.hpp"
#include "Error.hpp"

sdf::Texture::Texture(const std::string &path)
{
    float borderColor[] = {1.0, 0.0, 1.0, 1.0};

    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);

    // If the texture is not mapped correctly, just extends the last pixel's color to the edge
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // Set the texture to add a fushia border when the texture is not big enough (GL_CLAMP_TO_BORDER)
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    // Add suport for mimaps
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // tell stb_image.h to flip loaded texture's on the y-axis
    stbi_set_flip_vertically_on_load(true);

    // Retreive texture from disk & generate mimaps
    unsigned char *data = stbi_load(path.c_str(), &_width, &_height, &_nrChannels, 0);
    int format = (_nrChannels == 4) ? GL_RGBA : GL_RGB;
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, format, _width, _height,
            0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        throw sdf::Error("sdf::Texture::Texture: Failed to load texture " + path
            + " - " + stbi_failure_reason());
    }
    stbi_image_free(data);
}

sdf::Texture::~Texture(void)
{
}

unsigned int sdf::Texture::get(void)
{
    return _texture;
}
