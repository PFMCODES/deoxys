#define GLFW_INCLUDE_NONE
#include <iostream>
#include "GLFW/glfw3.h"

int shutdown();
void error_callback(int error_code, const char* description);

int destroyWindow(GLFWwindow* window);
GLFWwindow* createWindow(const char* title, const int* h, const int* w, bool maximized = false);