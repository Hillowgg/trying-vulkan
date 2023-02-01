#pragma once

#include <string>
#include <vector>

#include "lveDevice.hpp"

namespace lve {
    struct PipelineConfigInfo {
//        VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
//        VkPipelineInputAssemblyStateCreateInfo inputAssembly{};
//        VkViewport viewport{};
//        VkRect2D scissor{};
//        VkPipelineViewportStateCreateInfo viewportState{};
//        VkPipelineRasterizationStateCreateInfo rasterizer{};
//        VkPipelineMultisampleStateCreateInfo multisampling{};
//        VkPipelineColorBlendAttachmentState colorBlendAttachment{};
//        VkPipelineColorBlendStateCreateInfo colorBlending{};
//        VkPipelineLayout pipelineLayout{};
//        VkRenderPass renderPass{};
//        uint32_t subpass{};
    };

    class Pipeline {
    public:
        Pipeline(
                LveDevice &device,
                const std::string &vertFilepath,
                const std::string &fragFilepath,
                const PipelineConfigInfo &configInfo);

        ~Pipeline();

        Pipeline(const Pipeline &) = delete;

        void operator=(const Pipeline &) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string &filepath);

        static void createGraphicsPipeline(
                const std::string &vertFilepath,
                const std::string &fragFilepath,
                const PipelineConfigInfo &configInfo
                );

        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

        LveDevice &lveDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule shaderPipeline;
        VkShaderModule vertShaderModule;
    };
} // namespace lve