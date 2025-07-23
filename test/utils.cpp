#include "utils.h"
#include <fstream>
#include <gtest/gtest.h>

auto readTextFile(const std::filesystem::path& path) -> std::string {
    std::ifstream f(path.string());
    if (!f)
        throw std::ios::failure("Failed to open file " + path.string() + " for reading");

    f.seekg(std::ios::end);
    const auto size = f.tellg();
    f.seekg(std::ios::beg);

    std::string content;
    content.reserve(size);
    content.assign(std::istreambuf_iterator<char>{f}, std::istreambuf_iterator<char>{});
    return content;
}

auto testName() -> std::string {
    return ::testing::UnitTest::GetInstance()->current_test_info()->name();
}

auto testDir() -> std::filesystem::path {
    return std::filesystem::path{ c_dataDir } / testName();
}
