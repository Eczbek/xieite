#ifndef DETAIL_XIEITE_HEADER_MATH_DURATION_CAST
#	define DETAIL_XIEITE_HEADER_MATH_DURATION_CAST
#
#	include <chrono>
#	include <tuple>
#	include "../trait/is_duration.hpp"

namespace xieite {
	template<xieite::is_duration... Durations>
	[[nodiscard]] constexpr std::tuple<Durations...> duration_cast(xieite::is_duration auto duration) noexcept {
		std::tuple<Durations...> results;
		(..., (duration -= (std::get<Durations>(results) = std::chrono::duration_cast<Durations>(duration))));
		return results;
	}
}

#endif

// Stolen from orlac (https://github.com/vorlac)
