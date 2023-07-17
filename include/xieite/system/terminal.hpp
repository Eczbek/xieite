#ifndef XIEITE_HEADER_SYSTEM_TERMINAL
#	define XIEITE_HEADER_SYSTEM_TERMINAL

#	include <iostream>
#	include <xieite/system/StandardStreamsController.hpp>

namespace xieite::system {
	inline auto terminal = xieite::system::StandardStreamsController<std::cin, std::cout>();
}

#endif
