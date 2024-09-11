export module xieite:time.compilation;

import std;
import :containers.FixedMap;
import :math.parse;

constexpr xieite::containers::FixedMap<std::string_view, int, 12> months = {
	{ "Jan", 1 },
	{ "Feb", 2 },
	{ "Mar", 3 },
	{ "Apr", 4 },
	{ "May", 5 },
	{ "Jun", 6 },
	{ "Jul", 7 },
	{ "Aug", 8 },
	{ "Sep", 9 },
	{ "Oct", 10 },
	{ "Nov", 11 },
	{ "Dec", 12 }
};

export namespace xieite::time::compilation {
	static constexpr int year = xieite::math::parse<int>(std::string_view(__DATE__).substr(7));

	static constexpr int month = months[std::string_view(__DATE__).substr(0, 3)];

	static constexpr int day = xieite::math::parse<int>(std::string_view(__DATE__).substr(4, 2));

	static constexpr int hour = xieite::math::parse<int>(std::string_view(__TIME__).substr(0, 2));

	static constexpr int minute = xieite::math::parse<int>(std::string_view(__TIME__).substr(3, 2));

	static constexpr int second = xieite::math::parse<int>(std::string_view(__TIME__).substr(6));
}
