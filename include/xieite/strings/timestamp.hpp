#ifndef XIEITE_HEADER_STRINGS_TIMESTAMP
#	define XIEITE_HEADER_STRINGS_TIMESTAMP

#	include <chrono>
#	include <string>
#	include "../concepts/temporal_duration.hpp"
#	include "../math/stringify.hpp"
#	include "../strings/pad_front.hpp"

namespace xieite::strings {
	template<xieite::concepts::TemporalDuration Duration>
	[[nodiscard]] constexpr std::string timestamp(Duration value, const bool date = true, const bool time = true, const bool subsecond = false) noexcept {
		const auto years = std::chrono::duration_cast<std::chrono::years>(value);
		value -= std::chrono::duration_cast<Duration>(years);
		const auto months = std::chrono::duration_cast<std::chrono::months>(value);
		value -= std::chrono::duration_cast<Duration>(months);
		const auto days = std::chrono::duration_cast<std::chrono::days>(value);
		value -= std::chrono::duration_cast<Duration>(days);
		const auto hours = std::chrono::duration_cast<std::chrono::hours>(value);
		value -= std::chrono::duration_cast<Duration>(hours);
		const auto minutes = std::chrono::duration_cast<std::chrono::minutes>(value);
		value -= std::chrono::duration_cast<Duration>(minutes);
		const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(value);
		value -= std::chrono::duration_cast<Duration>(seconds);
		const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(value);
		value -= std::chrono::duration_cast<Duration>(milliseconds);
		const auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(value);
		value -= std::chrono::duration_cast<Duration>(microseconds);
		const auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(value);
		std::string result;
		if (date) {
			result += xieite::strings::padFront(xieite::math::stringify(years.count()), 4, '0') + '-' + xieite::strings::padFront(xieite::math::stringify(months.count()), 2, '0') + '-' + xieite::strings::padFront(xieite::math::stringify(days.count()), 2, '0');
		}
		if (time) {
			if (date) {
				result += ' ';
			}
			result += xieite::strings::padFront(xieite::math::stringify(hours.count()), 2, '0') + ':' + xieite::strings::padFront(xieite::math::stringify(minutes.count()), 2, '0') + ':' + xieite::strings::padFront(xieite::math::stringify(seconds.count()), 2, '0');
		}
		if (subsecond) {
			if (date || time) {
				result += ' ';
			}
			result += xieite::strings::padFront(xieite::math::stringify(milliseconds.count()), 4, '0') + ':' + xieite::strings::padFront(xieite::math::stringify(microseconds.count()), 4, '0') + ':' + xieite::strings::padFront(xieite::math::stringify(nanoseconds.count()), 4, '0');
		}
		return result;
	}
}

#endif
