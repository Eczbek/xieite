#ifndef XIEITE_HEADER_TIME_DECADES
#	define XIEITE_HEADER_TIME_DECADES

#	include <chrono>
#	include <cstdint>
#	include <ratio>

namespace xieite::time {
	using Decades = std::chrono::duration<std::intmax_t, std::ratio<315569520>>;
}

#endif
