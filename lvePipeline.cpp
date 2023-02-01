#include "lvePipeline.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace lve {



    std::vector<char> Pipeline::readFile(const std::string &filepath) {
        std::ifstream file{filepath, std::ios::ate | std::ios::binary};

        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file!: " + filepath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();

        return buffer;
    }

    Pipeline::~Pipeline() {
        vkDestroyShaderModule(lveDevice.device(), vertShaderModule, nullptr);
        vkDestroyShaderModule(lveDevice.device(), shaderPipeline, nullptr);
        vkDestroyPipeline(lveDevice.device(), graphicsPipeline, nullptr);

    }

    Pipeline::Pipeline(LveDevice &device,
                       const std::string &vertFilepath,
                       const std::string &fragFilepath,
                       const PipelineConfigInfo &configInfo) : lveDevice{device} {
        createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);

    }

    void Pipeline::createGraphicsPipeline(
            const std::string &vertFilepath,
            const std::string &fragFilepath,
            const PipelineConfigInfo &configInfo
    ) {

        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex Shader Code size:" << vertCode.size() << std::endl;
        std::cout << "Fragment Shader Code size:" << fragCode.size() << std::endl;
    }

    void Pipeline::createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule) {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

        if (vkCreateShaderModule(
                lveDevice.device(),
                &createInfo,
                nullptr,
                shaderModule) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create shader module!");
        }

    }

    PipelineConfigInfo Pipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
        PipelineConfigInfo configInfo{};

        return configInfo;
    }
}

