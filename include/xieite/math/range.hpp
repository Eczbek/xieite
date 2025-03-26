#ifndef DETAIL_XIEITE_HEADER_MATH_RANGE
#	define DETAIL_XIEITE_HEADER_MATH_RANGE
#
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include "../fn/unroll.hpp"

namespace xieite {
	template<std::size_t size, auto start = 0uz, std::same_as<decltype(start)> auto step = 1uz, std::integral T = decltype(start)>
	constexpr std::array<T, size> range = xieite::unroll<size>([]<std::size_t... i> static {
		return std::array<T, size> { (static_cast<T>(i) * step + start)... };
	});
}

#endif
