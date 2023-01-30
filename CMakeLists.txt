cmake_minimum_required(VERSION 3.24)
project(vulcan)

set(CMAKE_CXX_STANDARD 23)


find_package(Vulkan REQUIRED)

include_directories(/opt/homebrew/Cellar/glm/0.9.9.8/include)
include_directories(/opt/homebrew/Cellar/glfw/3.3.7/include)

add_executable(vulc main.cpp window.cpp window.hpp app.cpp app.hpp)

target_link_libraries(vulc PRIVATE Vulkan::Vulkan)
target_link_libraries(vulc PRIVATE /opt/homebrew/Cellar/glfw/3.3.7/lib/libglfw.3.3.dylib)


