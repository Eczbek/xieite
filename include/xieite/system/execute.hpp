#ifndef XIEITE_HEADER_SYSTEM_EXECUTE
#	define XIEITE_HEADER_SYSTEM_EXECUTE

#	include <string>
#	include "../streams/pipe.hpp"
#	include "../streams/read.hpp"

namespace xieite::system {
	inline std::string execute(const std::string_view command) noexcept {
		return xieite::streams::read(xieite::streams::Pipe(std::string(command), std::string(1, 'r')).file());
	}
}

#endif
