#pragma once

#include <concepts>
#include <ostream>

namespace x4 {
	template<typename T>
	concept isstreamout = requires (T x, std::ostream ostream) {
		{ ostream << x } -> std::convertible_to<std::ostream&>;
	};
}
