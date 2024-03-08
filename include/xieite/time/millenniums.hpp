#ifndef XIEITE_HEADER_TIME_MILLENNIUMS
#	define XIEITE_HEADER_TIME_MILLENNIUMS

#	include <chrono>
#	include <cstdint>
#	include <ratio>

namespace xieite::time {
	using Millenniums = std::chrono::duration<std::intmax_t, std::ratio<31556952000>>;
}

#endif
