cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME Renderer)
set(CMAKE_CXX_STANDARD 17)

set(WINDOW_NAME "Renderer")
set(WINDOW_WIDTH 1920)
set(WINDOW_HEIGHT 1080)

set(glfw3_DIR "vcpkg_installed/x64-windows/share/glfw3")
set(glad_DIR "vcpkg_installed/x64-windows/share/glad")

project(Renderer)

add_executable(Renderer src/main.cpp)

# vcpkg
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(Renderer PRIVATE spdlog::spdlog_header_only)

# glfw3
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Renderer PRIVATE glfw)

# glad
find_package(glad CONFIG REQUIRED)
target_link_libraries(Renderer PRIVATE glad::glad)


target_compile_definitions(${PROJECT_NAME} PUBLIC
        WINDOW_NAME="${WINDOW_NAME}"
        WINDOW_WIDTH=${WINDOW_WIDTH}
        WINDOW_HEIGHT=${WINDOW_HEIGHT})

## (glfw3)
#include(Dependecy.cmake)
#
#target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
#target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
#target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})
#add_dependencies(${PROJECT_NAME} ${DEP_LIST})