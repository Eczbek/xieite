#ifndef XIEITE_HEADER_TIME_CENTURIES
#	define XIEITE_HEADER_TIME_CENTURIES

#	include <chrono>
#	include <cstdint>
#	include <ratio>

namespace xieite::time {
	using Centuries = std::chrono::duration<std::intmax_t, std::ratio<3155695200>>;
}

#endif
