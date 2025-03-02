cmake_minimum_required(VERSION 3.5.0)
project(imgui-example VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenGL REQUIRED)

link_directories(libs/glfw)

include_directories(libs/glfw)

add_library(imgui 
        libs/imgui/imgui.cpp
        libs/imgui/imgui_draw.cpp 
        libs/imgui/imgui_demo.cpp 
        libs/imgui/imgui_widgets.cpp 
        libs/imgui/imgui_tables.cpp
        libs/imgui/backends/imgui_impl_glfw.cpp 
        libs/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories( imgui PUBLIC
        ${PROJECT_SOURCE_DIR}/libs/imgui
)

add_library(implot 
        libs/implot/implot.cpp
        libs/implot/implot_demo.cpp
        libs/implot/implot_items.cpp
)

target_include_directories( implot PUBLIC
        ${PROJECT_SOURCE_DIR}/libs/implot
        ${PROJECT_SOURCE_DIR}/libs/imgui
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} glfw imgui implot)

target_include_directories( ${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/libs/imgui
        ${PROJECT_SOURCE_DIR}/libs/implot
)



include(CTest)
enable_testing()