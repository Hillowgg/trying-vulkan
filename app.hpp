#pragma once

#include "window.hpp"
#include "lvePipeline.hpp"

namespace lve {
    class App {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();

        private:
            Window Window{WIDTH, HEIGHT, "Vulkan hillow!"};
            Pipeline Pipeline{"shaders/simpleShader.vert.spv", "shaders/simpleShader.frag.spv"};
    };
} // namespace lve