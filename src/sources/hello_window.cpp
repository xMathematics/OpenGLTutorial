//
// Created by Dongz on 2022/10/7.
//


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    /*
     * major:主版本号
     * minor:次版本号
     * core_profile:核心模式
     * */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "First Windows", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //通知GLFW将我们窗口的上下文设置为当前线程的主上下文
    glfwMakeContextCurrent(window);
    //注册帧缓冲函数，告诉GLFW 我们希望每当窗口调整大小的时候调用这个函数
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /*
     * GLAD用来管理OpenGL的函数指针
     * 所以在调用任何OpenGL函数的时候需要初始化GLAD
     * 我们给GLAD传入了用来 加载 系统相关的 OpenGL函数指针地址 的函数
     * glfwGetProcAddress根据我们编译的系统定义了正确的函数
     * */
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    /*
     * GLFW 退出之前始终保持运行
     * glfwWindowShouldClose函数在我们每次循环的开始前检查一次GLFW是否被要求退出
     * glfwPollEvents函数检查有没有触发什么事件 更新窗口状态，并调用对应的回调函数（可以通过回调方法手动设置）
     * glfwSwapBuffers函数会交换颜色缓冲（它是一个存储着GLFW窗口每一个像素颜色值的大缓冲），在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上
     * */
    /*
     * 双缓冲
     * 单缓冲绘图可能会导致图像闪烁问题
     * 原因：
     *      因为生成的图像不是一下子被绘制出来的，而是按照从左到右，从上到下逐像素的绘制而成
     *      最终图像不是瞬间显示给用户，而是通过一步一步生成，这回导致渲染的结果不真实
     *
     * 前缓冲保存最终输出的图像，它会在屏幕上显示
     * 所有的渲染指令都会在后缓冲上绘制
     * 当所有的渲染指令执行完毕后，交换前缓冲和后缓冲，这样图像会立即显示出来
     * */
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();

        //状态设置函数
        glClearColor(0.1f, 0.5f, 0.3f, 0.1f);
        //状态使用函数
        /*
         * glClear清空颜色缓冲，接收一个缓冲位来指定要清空的缓冲
         *
         * GL_COLOR_BUFFER_BIT 颜色缓冲
         * GL_DEPTH_BUFFER_BIT 深度缓冲
         * GL_STENCIL_BUFFER_BIT 模板缓冲
         * */
        glClear(GL_COLOR_BUFFER_BIT);
    }

    /*
     * 渲染结束后，释放之前分配的所有资源
     * */
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}


/*
 * 输入控制
 * glfwGetKey函数输入的两个参数是一个窗口和一个按键，返回值的这个按键是否被按下
 * 本次输入的esc按键作为参数
 * */
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


/*
 * 帧缓冲大小函数
 * 每次窗口大小被调整的时候被调用
 * */
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    /**
     * 渲染之前需要告诉OpenGL渲染窗口的尺寸大小
     * glViewport函数的前两个参数控制窗口左下角的位置
     * 后两个参数控制控制渲染窗口的宽度和高度（像素）
     *
     * OpenGL幕后会对定义的位置和宽高进行2D坐标的转换
     * 将OpenGL中的位置坐标转换为屏幕坐标
     * 处理后的OpenGL坐标范围是（-1， 1）
     **/
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}