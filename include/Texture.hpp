#pragma once
#ifndef GRAFFITI_TEXTURE_HPP
#define GRAFFITI_TEXTURE_HPP

#include "Core.hpp"

namespace Graffiti {
    class Texture {
    public:
        void attach(const std::string &);

        unsigned int getTexture() const;

        void use();

    private:
        unsigned int _textureID;
    };
}
#endif // !GRAFFITI_TEXTURE_HPP
