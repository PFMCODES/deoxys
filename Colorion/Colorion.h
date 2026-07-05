#pragma once
#include <cstdint>

namespace Colorion
{
    // 1. Keeps your original packed integer logic intact
    uint32_t rgb(uint8_t r, uint8_t g, uint8_t b);
    uint32_t rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    // 2. Add this struct for OpenGL compatibility
    struct GLColor {
        float channels[4]; // Stores R, G, B, A as floats
    };

    // 3. Overloaded functions that return OpenGL-ready structures
    GLColor gl_rgb(uint8_t r, uint8_t g, uint8_t b);
    GLColor gl_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    GLColor gl_hex(uint32_t hexValue, bool hasAlpha = false);
    struct Color {
        std::uint8_t r; // Red channel (0-255)
        std::uint8_t g; // Green channel (0-255)
        std::uint8_t b; // Blue channel (0-255)
        std::uint8_t a = 255; // Alpha channel for transparency (defaults to fully opaque)
    };
    
    struct SystemColor
    {
        Color Red = { 255, 0, 0, 255 };
        Color Yellow = { 255, 255, 0, 255 };
        Color Green = { 0, 255, 0, 255 };
        Color Blue = { 0, 0, 255, 255 }; 
        Color White = { 255, 255, 255, 255 };
        Color Black = { 0, 0, 0, 255 };
        Color Transparent = { 0, 0, 0, 0 };
    };
}