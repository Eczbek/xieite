#ifndef XIEITE_HEADER_SYSTEM_EXECUTE
#	define XIEITE_HEADER_SYSTEM_EXECUTE

#	include <cstdio>
#	include <string>
#	include "../memory/get_page_size.hpp"
#	include "../streams/pipe.hpp"

namespace xieite::system {
	inline std::string execute(const std::string_view command) noexcept {
		const xieite::streams::Pipe pipe = xieite::streams::Pipe(std::string(command), std::string(1, 'r'));
		const std::size_t pageSize = xieite::memory::getPageSize();
		std::string result;
		while (true) {
			std::string buffer = std::string(pageSize, '\0');
			if (!std::fread(buffer.data(), 1, buffer.size(), pipe.file())) {
				break;
			}
			result += buffer;
		}
		return result;
	}
}

#endif
