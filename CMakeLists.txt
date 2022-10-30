cmake_minimum_required(VERSION 3.23)
project(OpenGLTutorial)

set(CMAKE_CXX_STANDARD 17)

add_executable(OpenGLTutorial
        src/glad.c
        src/sources/my_triangle.cpp)



include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(OpenGLTutorial ${PROJECT_SOURCE_DIR}/lib/glfw3.dll)