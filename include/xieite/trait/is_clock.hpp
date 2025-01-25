#pragma once

#include <chrono>

namespace xieite {
	template<typename T>
	concept is_clock = std::chrono::is_clock_v<T>;
}
