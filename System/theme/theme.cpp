#include "./theme.h"
#include "../System.h"
#include <string>
#include <memory>
#include <array>

#if defined(_WIN32)
    #include <windows.h>
#elif defined(__linux__)
    #include <iostream>
#elif defined(__APPLE__)
    #include <CoreFoundation/CoreFoundation.h>
#endif

namespace Theme {

    themes getSystemTheme() {
        #if defined(_WIN32)
            HKEY hKey;
            LONG res = RegOpenKeyExW(HKEY_CURRENT_USER, 
                L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 
                0, KEY_READ, &hKey);
                
            if (res != ERROR_SUCCESS) return themes::Light;

            DWORD value = 1; // Default to Light Mode
            DWORD bufferSize = sizeof(value);
            
            res = RegQueryValueExW(hKey, L"AppsUseLightTheme", nullptr, nullptr, 
                                   reinterpret_cast<LPBYTE>(&value), &bufferSize);
            RegCloseKey(hKey);
            
            // 0 means Dark Mode is active
            if (res == ERROR_SUCCESS && value == 0) {
                return themes::Dark;
            }
            return themes::Light;

        #elif defined(__APPLE__)
            themes activeTheme = themes::Light;
            
            // Look up AppleInterfaceStyle safely via CoreFoundation C API
            CFStringRef key = CFStringCreateWithCString(nullptr, "AppleInterfaceStyle", kCFStringEncodingUTF8);
            CFPropertyListRef plist = CFPreferencesCopyAppValue(key, kCFPreferencesCurrentApplication);
            
            if (plist != nullptr) {
                if (CFGetTypeID(plist) == CFStringGetTypeID()) {
                    CFStringRef styleStr = static_cast<CFStringRef>(plist);
                    // If the property exists and matches "Dark"
                    if (CFStringCompare(styleStr, CFSTR("Dark"), 0) == kCFCompareEqualTo) {
                        activeTheme = themes::Dark;
                    }
                }
                CFRelease(plist);
            }
            CFRelease(key);
            return activeTheme;

        #elif defined(__linux__)
            std::array<char, 128> buffer;
            std::string result;
            
            // Standard modern cross-desktop check for the freedesktop color-scheme preference
            std::unique_ptr<FILE, decltype(&pclose)> pipe(
                popen("gsettings get org.gnome.desktop.interface color-scheme 2>/dev/null", "r"), pclose);
                
            if (pipe) {
                while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
                    result += buffer.data();
                }
            }
            
            // Usually returns variants of 'prefer-dark'
            if (result.find("dark") != std::string::npos) {
                return themes::Dark;
            }
            return themes::Light;
            
        #else
            return themes::Light; // Fallback default
        #endif
    }
}