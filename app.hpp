#pragma once

#include "window.hpp"

namespace lve {
    class App {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();

        private:
            Window Window{WIDTH, HEIGHT, "Vulkan hillow!"};
    };
} // namespace lve