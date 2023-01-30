#include "app.hpp"

namespace lve {
    void App::run() {
        while (!Window.shouldClose()) {
            glfwPollEvents();
        }
    }
};