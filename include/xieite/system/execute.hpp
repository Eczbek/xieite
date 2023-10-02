#ifndef XIEITE_HEADER__SYSTEM__EXECUTE
#	define XIEITE_HEADER__SYSTEM__EXECUTE

#	include <cstdio>
#	include <string>
#	include <string_view>
#	include "../functors/ScopeGuard.hpp"
#	include "../memory/getPageSize.hpp"
#	include "../streams/closePipe.hpp"
#	include "../streams/openPipe.hpp"

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

#endif
