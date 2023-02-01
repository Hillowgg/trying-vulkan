#pragma once

#include "window.hpp"
#include "lvePipeline.hpp"
#include "lveDevice.hpp"

namespace lve {
    class App {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        Window Window{WIDTH, HEIGHT, "Vulkan hillow!"};
        LveDevice lveDevice{Window};
        Pipeline Pipeline{
            lveDevice,
            "shaders/simpleShader.vert.spv",
            "shaders/simpleShader.frag.spv",
            Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
        };
    };
} // namespace lve