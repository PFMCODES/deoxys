#include <iostream>
#include "./window.h"
#include <glad/gl.h>

int main() {
    GLFWwindow* window = createWindow("test window", new int(600), new int(800));

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