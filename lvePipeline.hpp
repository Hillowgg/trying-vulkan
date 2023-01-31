#pragma once

#include <string>
#include <vector>

namespace lve {
    class Pipeline {
        public:
            Pipeline(const std::string& vertFilepath, const std::string& fragFilepath);
//            ~Pipeline();

//            Pipeline(const Pipeline &) = delete;
//            Pipeline &operator=(const Pipeline &) = delete;

    private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
    };
} // namespace lve