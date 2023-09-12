#ifndef XIEITE_HEADER__SYSTEM__EXECUTE
#	define XIEITE_HEADER__SYSTEM__EXECUTE

#	include <cstdio>
#	include <string>
#	include <string_view>
#	include "../functors/ScopeGuard.hpp"
#	include "../memory/getPageSize.hpp"
#	include "../system/closeFilePipe.hpp"
#	include "../system/openFilePipe.hpp"

namespace xieite::system {
	inline std::string execute(const std::string_view command) noexcept {
		std::FILE* const pipe = xieite::system::openFilePipe(command.data(), "r");
		const xieite::functors::ScopeGuard pipeGuard([pipe] {
			xieite::system::closeFilePipe(pipe);
		});
		const std::size_t pageSize = xieite::memory::getPageSize();
		std::string result;
		while (true) {
			std::string buffer = std::string(pageSize, '\0');
			if (!std::fread(buffer.data(), sizeof(char), buffer.size(), pipe.get())) {
				break;
			}
			result += buffer;
		}
		return result;
	}
}

#endif
