#include <iostream>
#include "./window.h"
#include <glad/gl.h>
#include <cstdio>

int main() {
    GLFWwindow* window = createWindow("Deoxys", new int(600), new int(800), true);

    while (!glfwWindowShouldClose(window))
    {
        // Draw here

        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    destroyWindow(window);
    return 0;
}