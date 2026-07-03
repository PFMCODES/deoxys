#include "Colorion.h"
#include <cstdint>
#include <iostream>

namespace Colorion
{
    // Your existing integer functions
    uint32_t rgb(uint8_t r, uint8_t g, uint8_t b) {
        const uint32_t red = static_cast<uint32_t>(r) << 16;
        const uint32_t green = static_cast<uint32_t>(g) << 8;
        const uint32_t blue = static_cast<uint32_t>(b);
        return red | green | blue;
    }

    uint32_t rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        const uint32_t red = static_cast<uint32_t>(r) << 24; // Note: Fixed shift to 24 for proper RGBA packing
        const uint32_t green = static_cast<uint32_t>(g) << 16;
        const uint32_t blue = static_cast<uint32_t>(b) << 8;
        const uint32_t alpha = static_cast<uint32_t>(a);
        return red | green | blue | alpha;
    }

    // New OpenGL Floating Point Overloads
    GLColor gl_rgb(uint8_t r, uint8_t g, uint8_t b) {
        return GLColor{{ r / 255.0f, g / 255.0f, b / 255.0f, 1.0f }};
    }

    GLColor gl_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        return GLColor{{ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }};
    }

    GLColor gl_hex(uint32_t hexValue, bool hasAlpha) {
        if (hasAlpha) {
            uint8_t r = (hexValue >> 24) & 0xFF;
            uint8_t g = (hexValue >> 16) & 0xFF;
            uint8_t b = (hexValue >> 8)  & 0xFF;
            uint8_t a = hexValue         & 0xFF;
            return gl_rgba(r, g, b, a);
        } else {
            uint8_t r = (hexValue >> 16) & 0xFF;
            uint8_t g = (hexValue >> 8)  & 0xFF;
            uint8_t b = hexValue         & 0xFF;
            return gl_rgb(r, g, b);
        }
    }
}