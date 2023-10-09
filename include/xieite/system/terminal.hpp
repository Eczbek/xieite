#ifndef XIEITE_HEADER__SYSTEM__TERMINAL
#	define XIEITE_HEADER__SYSTEM__TERMINAL

#	include <iostream>
#	include "../streams/standard_controller.hpp"

namespace xieite::system {
	inline const xieite::streams::StandardController terminal = xieite::streams::StandardController(std::cin, std::cout);
}

#endif
