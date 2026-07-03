#define GLFW_INCLUDE_NONE
#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "./Colorion/Colorion.h"
#include <iomanip>

int destroyWindow(GLFWwindow* window) {
    if (window) {
        glfwDestroyWindow(window);
        return 0;
    }

    return -1;
}

int shutdown() {
    glfwTerminate();
    return 0;
}

void error_callback(int error_code, const char* description) {
    std::cerr << "GLFW Error (" << error_code << "): " << description << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

GLFWwindow* createWindow(const char* title, const int* h, const int* w, bool maximized = false) {
    
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        error_callback(-1, "Failed to create GLFW window");
        return nullptr;
    }

    if (maximized) {
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    }

    GLFWwindow* window = glfwCreateWindow(*w, *h, title, nullptr, nullptr);

    if (!window)
    {
        error_callback(-1, "Failed to create GLFW window");
        shutdown();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL((GLADloadfunc)glfwGetProcAddress);
    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD!" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return nullptr;
    }

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);
    Colorion::GLColor white = Colorion::gl_rgba(255, 255, 255, 0.5);
    glClearColor(white.channels[0], white.channels[1], white.channels[2], white.channels[3]);
    std::cout << "Background Color: " << std::hex << white.channels[0] << ", " << white.channels[1] << ", " << white.channels[2] << ", " << white.channels[3] << std::dec << std::endl;
    glClear(GL_COLOR_BUFFER_BIT);

    return window;
}