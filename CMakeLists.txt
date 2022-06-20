cmake_minimum_required(VERSION 3.23)
project(learnOpengl
    VERSION 1.0
    DESCRIPTION "Learn OpenGL"
    LANGUAGES CXX C
)
set(CMAKE_SOURCE_DIR src)
include_directories(${CMAKE_SOURCE_DIR}/deps)
set(SOURCE_FILES 
    ${CMAKE_SOURCE_DIR}/deps/glad.c
    ${CMAKE_SOURCE_DIR}/deps/shader_loader.c
)
add_executable(hello_triangle
    ${SOURCE_FILES}
    src/hello_triangle.c
)

target_compile_definitions(hello_triangle
    PRIVATE 
    TEST_PREPROCESSOR)
target_compile_options(hello_triangle PRIVATE -Wall)
find_library(LIB_GLFW
    glfw
    REQUIRED
)
if (LIB_GLFW)
    message(STATUS "Found GLFW")
    target_link_libraries(hello_triangle
        ${LIB_GLFW})
else()
    message(FATAL_ERROR "GLFW library not found")
endif()
