#ifndef XIEITE_HEADER_TIME_COMPILATION
#	define XIEITE_HEADER_TIME_COMPILATION

#	include <chrono>
#	include <string_view>
#	include "../containers/fixed_map.hpp"
#	include "../math/parse.hpp"

namespace xieite::time {
	static constexpr std::chrono::seconds compilation = std::chrono::years(xieite::math::parse<int>(std::string_view(__DATE__).substr(7))) + std::chrono::months((xieite::containers::FixedMap<std::string_view, int, 12> { { "Jan", 1 }, { "Feb", 2 }, { "Mar", 3 }, { "Apr", 4 }, { "May", 5 }, { "Jun", 6 }, { "Jul", 7 }, { "Aug", 8 }, { "Sep", 9 }, { "Oct", 10 }, { "Nov", 11 }, { "Dec", 12 } })[std::string_view(__DATE__).substr(0, 3)]) + std::chrono::days(xieite::math::parse<int>(std::string_view(__DATE__).substr(4, 2))) + std::chrono::hours(xieite::math::parse<int>(std::string_view(__TIME__).substr(0, 2))) + std::chrono::minutes(xieite::math::parse<int>(std::string_view(__TIME__).substr(3, 2))) + std::chrono::seconds(xieite::math::parse<int>(std::string_view(__TIME__).substr(6))); // Must be declared static
}

#endif
