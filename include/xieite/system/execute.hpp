#ifndef XIEITE_HEADER__SYSTEM__EXECUTE
#	define XIEITE_HEADER__SYSTEM__EXECUTE

#	include <cstdio>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../memory/getPageSize.hpp"
#	include "../system/closeFilePipe.hpp"
#	include "../system/openFilePipe.hpp"

namespace xieite::system {
	inline std::string execute(const std::string_view command) noexcept {
		const auto pipe = std::unique_ptr<std::FILE, decltype([](std::FILE* const file) {
			xieite::system::closeFilePipe(file);
		})>(xieite::system::openFilePipe(command.data(), "r"));
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
