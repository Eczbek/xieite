#pragma once

#include <concepts>
#include <istream>

namespace x4 {
	template<typename T>
	concept isstreamin = requires (T x, std::istream istream) {
		{ istream >> x } -> std::convertible_to<std::istream&>;
	};
}
