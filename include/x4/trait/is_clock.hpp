#pragma once

#include <chrono>

namespace x4 {
	template<typename T>
	concept isclock = std::chrono::is_clock_v<T>;
}
