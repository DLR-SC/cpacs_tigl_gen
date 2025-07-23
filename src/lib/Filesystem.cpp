#include "Filesystem.h"

#include <algorithm>
#include <fstream>
#include <utility>

namespace tigl {
	auto readFile(const std::filesystem::path& filename) -> std::string {
		std::ifstream existingFile(filename.string());
		if (!existingFile)
			return{};

		// read file to string
		existingFile.seekg(0, std::ifstream::end);
		const auto length = existingFile.tellg();
		existingFile.seekg(0, std::ifstream::beg);
		std::string content;
		content.reserve(length);
		content.assign(std::istreambuf_iterator<char>{existingFile}, std::istreambuf_iterator<char>{});
		return content;
	}

	File::File(std::filesystem::path filename)
		: m_stream(new std::ostringstream), m_filename(std::move(filename)) {}

	auto File::path() const -> const std::filesystem::path&
	{
		return m_filename;
	}

	auto File::stream() -> std::ostream& {
		return *m_stream;
	}

	void Filesystem::flushToDisk() {
		for (auto& file : m_files) {
			const auto& newContent = file.m_stream->str();

			// check if a file already exists
			if (std::filesystem::exists(file.m_filename)) {
				// read existing file to string and compare
				const auto& content = readFile(file.m_filename);

				// if existing file has same content, skip overwriting it
				if (content == newContent) {
					skipped++;
					continue;
				}

				overwritten++;
			}
			else
				newlywritten++;

			// write new content to file
			std::ofstream f(file.m_filename.string());
			f.exceptions(std::ios::failbit | std::ios::badbit);
			f.write(newContent.c_str(), newContent.size());
			f.close();
		}
	}

	auto Filesystem::newFile(std::filesystem::path filename) -> File& {
		m_files.emplace_back(std::move(filename));
		return m_files.back();
	}

	void Filesystem::removeIfExists(const std::filesystem::path& path) {
		if (std::filesystem::exists(path)) {
			std::filesystem::remove(path);
			deleted++;
		}
	}

	void Filesystem::mergeFilesInto(std::filesystem::path filename) {
		File f(std::move(filename));
		sortFiles();
		for (auto& file : m_files) {
			auto str = file.m_stream->str();
			f.m_stream->write(str.c_str(), str.size());
		}
		m_files.clear();
		m_files.push_back(std::move(f));
	}

	void Filesystem::sortFiles() {
		std::sort(std::begin(m_files), std::end(m_files), [](const File& a, const File& b) {
			return a.path() < b.path();
		});
		// ensure that header files come first
		std::sort(std::begin(m_files), std::end(m_files), [](const File& a, const File& b) {
			return a.path().extension() > b.path().extension();
		});
	}
}
