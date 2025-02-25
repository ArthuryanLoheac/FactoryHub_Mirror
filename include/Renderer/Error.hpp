/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Error
*/

#pragma once
#include <exception>
#include <string>

namespace sdf
{
    class Error : public std::exception
    {
        public:
            Error(const std::string &what);
            const char *what(void) const noexcept;
        private:
            const std::string _what;
    };
}
