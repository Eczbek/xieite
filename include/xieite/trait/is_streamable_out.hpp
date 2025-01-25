#pragma once

#include <concepts>
#include <ostream>

namespace xieite {
	template<typename T>
	concept is_streamable_out = requires (T x, std::ostream ostream) {
		{ ostream << x } -> std::convertible_to<std::ostream&>;
	};
}

// Thanks to fux for original code
