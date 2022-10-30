//
// Created by Dongz on 2022/10/26.
//

#include "glad/glad.h"
#include "glfw/glfw3.h"

#include <iostream>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "my window", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout<<"window create fail"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
