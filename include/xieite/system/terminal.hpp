#ifndef XIEITE_HEADER__SYSTEM__TERMINAL
#	define XIEITE_HEADER__SYSTEM__TERMINAL

#	include <iostream>
#	include "../system/StandardStreamsController.hpp"

namespace xieite::system {
	inline auto terminal = xieite::system::StandardStreamsController<std::cin, std::cout>();
}

#endif
