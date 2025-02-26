/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Error
*/

#include "Sdf.hpp"

sdf::Error::Error(const std::string &what)
    : _what(what)
{}

const char *sdf::Error::what(void) const noexcept
{
    return _what.c_str();
}
