#pragma once

#include <cstdio>
#include <string>
#include <string_view>
#include "../functors/scope_guard.hpp"
#include "../memory/get_page_size.hpp"
#include "../streams/close_pipe.hpp"
#include "../streams/open_pipe.hpp"

namespace xieite::system {
	inline std::string execute(const std::string_view command) noexcept {
		std::FILE* const pipe = xieite::streams::openPipe(command.data(), "r");
		const xieite::functors::ScopeGuard pipeGuard = xieite::functors::ScopeGuard([pipe] {
			xieite::streams::closePipe(pipe);
		});
		const std::size_t pageSize = xieite::memory::getPageSize();
		std::string result;
		while (true) {
			std::string buffer = std::string(pageSize, '\0');
			if (!std::fread(buffer.data(), sizeof(char), buffer.size(), pipe)) {
				break;
			}
			result += buffer;
		}
		return result;
	}
}
