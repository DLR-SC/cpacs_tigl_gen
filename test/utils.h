#pragma once

#include <filesystem>

#include "paths.h"

auto readTextFile(const std::filesystem::path& path) -> std::string;

auto testName() -> std::string;

auto testDir() -> std::filesystem::path;
