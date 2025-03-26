#ifndef DETAIL_XIEITE_HEADER_MATH_CONV_DUR
#	define DETAIL_XIEITE_HEADER_MATH_CONV_DUR
#
#	include <chrono>
#	include <tuple>
#	include "../trait/is_dur.hpp"

namespace xieite {
	template<xieite::is_dur T, xieite::is_dur... Us>
	[[nodiscard]] constexpr std::tuple<Us...> conv_dur(T dur) noexcept {
		std::tuple<Us...> results;
		(..., (dur -= (std::get<Us>(results) = std::chrono::duration_cast<Us>(dur))));
		return results;
	}
}

#endif

// Stolen from orlac (https://github.com/vorlac)
