#pragma once

#include <filesystem>
#include <string>
#include <sstream>
#include <memory>
#include <deque>

namespace tigl {
    auto readFile(const std::filesystem::path& filename) -> std::string;

    class Filesystem;

    class File {
    public:
        File(std::filesystem::path filename);
        File(const File&) = delete;
        File& operator=(const File&) = delete;
        File(File&&) = default;
        File& operator=(File&&) = default;

        auto path() const -> const std::filesystem::path&;
        auto stream() -> std::ostream&;

    private:
        friend class Filesystem;

        std::unique_ptr<std::ostringstream> m_stream; // workaround for GCC < 5.0, where stringstream is not moveable ..
        std::filesystem::path m_filename;
    };

    class Filesystem {
    public:
        Filesystem() = default;

        auto newFile(std::filesystem::path filename) -> File&;
        void removeIfExists(const std::filesystem::path& path);

        void mergeFilesInto(std::filesystem::path filename);

        void flushToDisk();

        std::size_t newlywritten = 0;
        std::size_t overwritten = 0;
        std::size_t skipped = 0;
        std::size_t deleted = 0;

    private:
        void sortFiles();

        std::deque<File> m_files;
    };
}
