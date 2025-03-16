cmake_minimum_required(VERSION 3.5.0)
project(imgui-example VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set( IMGUI_COMPILE_GLFW ON  )
set( IMGUI_TARGET_WEB   OFF )

if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten" )
    set( IMGUI_COMPILE_GLFW OFF )
    set( IMGUI_TARGET_WEB   ON  )
endif()

## Add deps library
find_package(OpenGL REQUIRED)
link_directories(libs/glfw)
include_directories(libs/glfw)

# Imgui library
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

## Implot libray 
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


if( IMGUI_COMPILE_GLFW )
        target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} glfw imgui implot)
elseif( IMGUI_TARGET_WEB )
        ### Set specific flags for emcc and to place the result under ui-web
        set(CMAKE_EXECUTABLE_SUFFIX ".html")
        set_target_properties( ${PROJECT_NAME} PROPERTIES
        COMPILE_FLAGS "-O3 -g -s WASM=1 -s USE_WEBGL2=1 -s USE_GLFW=3 -s FULL_ES3=1 -s DEMANGLE_SUPPORT=1 -s DISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=1 -s ASSERTIONS=1 -s DISABLE_EXCEPTION_CATCHING=0 -s FORCE_FILESYSTEM=1"
        LINK_FLAGS "-O3 -g -s WASM=1 -s USE_WEBGL2=1 -s USE_GLFW=3 -s FULL_ES3=1 -s DEMANGLE_SUPPORT=1 -s DISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=1 -s ASSERTIONS=1 -s DISABLE_EXCEPTION_CATCHING=0 -s FORCE_FILESYSTEM=1 -s ALLOW_MEMORY_GROWTH=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['cwrap, FS']"
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ui-web
        # SUFFIX ".html"
        )
        target_link_libraries(${PROJECT_NAME} imgui implot)
        target_compile_definitions( ${PROJECT_NAME} PRIVATE -DIMGUIAPP_TARGET_WEB)
endif()

target_include_directories( ${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/libs/imgui
        ${PROJECT_SOURCE_DIR}/libs/implot
)

include(CTest)
enable_testing()