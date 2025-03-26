#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CLOCK
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CLOCK
#
#	include <chrono>

namespace xieite {
	template<typename T>
	concept is_clock = std::chrono::is_clock_v<T>;
}

#endif
