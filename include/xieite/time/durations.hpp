#ifndef XIEITE_HEADER_TIME_DURATIONS
#	define XIEITE_HEADER_TIME_DURATIONS

#	include <chrono>
#	include <cstdint>
#	include <ratio>

namespace xieite::time::durations {
	using Decades = std::chrono::duration<std::intmax_t, std::ratio<315569520>>;

	using Centuries = std::chrono::duration<std::intmax_t, std::ratio<3155695200>>;

	using Millenniums = std::chrono::duration<std::intmax_t, std::ratio<31556952000>>;

	using Epochs = std::chrono::duration<std::intmax_t, std::ratio<31556952000000>>;

	using Eons = std::chrono::duration<std::intmax_t, std::ratio<31556952000000000>>;
}

#endif
