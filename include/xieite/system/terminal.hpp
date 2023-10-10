#pragma once

#include <iostream>
#include "../streams/standard_controller.hpp"

namespace xieite::system {
	inline const xieite::streams::StandardController terminal = xieite::streams::StandardController(std::cin, std::cout);
}
