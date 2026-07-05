#include "../System.h"

namespace Theme {
    enum class themes
    {
        Light,
        Dark
    };

    themes getSystemTheme();
    struct internalTheme {
        System::ThemeColor Background = { 255, 255, 255, 255 }; // Default to white
        System::ThemeColor Text = { 0, 0, 0, 255 }; // Default to black
        System::ThemeColor Accent = { 0, 120, 215, 255 }; // Default to blue
    };
}