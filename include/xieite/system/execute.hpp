#ifndef XIEITE_HEADER_SYSTEM_EXECUTE
#	define XIEITE_HEADER_SYSTEM_EXECUTE

#	include "../macros/SYSTEM_TYPE.hpp"

#	if !XIEITE_SYSTEM_TYPE_UNIX && !XIEITE_SYSTEM_TYPE_WINDOWS
#		error "System not supported"
#	endif

#	include <cstdio>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../memory/bufferSize.hpp"
#	include "../system/closeFilePipe.hpp"
#	include "../system/openFilePipe.hpp"

namespace xieite::system {
	inline std::string execute(const std::string_view command) noexcept {
		const auto pipe = std::unique_ptr<std::FILE, decltype([](std::FILE* const file) {
			xieite::system::closeFilePipe(file);
		})>(xieite::system::openFilePipe(command.data(), "r"));
		std::string result;
		while (true) {
			std::string buffer = std::string(xieite::memory::bufferSize, '\0');
			if (!std::fread(buffer.data(), sizeof(char), buffer.size(), pipe.get())) {
				break;
			}
			result += buffer;
		}
		return result;
	}
}

#endif
