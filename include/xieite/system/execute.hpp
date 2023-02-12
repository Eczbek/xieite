#pragma once
#include <cstddef> // std::size_t
#include <cstdio> // pclose, popen, std::FILE, std::fread
#include <memory> // std::unique_ptr
#include <string> // std::string
#include <string_view> // std::string_view

namespace xieite::system {
	inline std::string execute(const std::string_view command, const std::size_t chunkSize = 1024) noexcept {
		const std::unique_ptr<std::FILE, decltype([](std::FILE* const file) -> void {
			pclose(file);
		})> pipe(popen(command.data(), "r"));
		std::string buffer;
		std::size_t status;
		do {
			std::string chunk(chunkSize, '\0');
			status = std::fread(chunk.data(), sizeof(char), chunkSize, pipe.get());
			buffer += chunk;
		} while (status);
		return buffer;
	}
}
