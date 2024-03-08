#ifndef XIEITE_HEADER_TIME_STRINGIFY
#	define XIEITE_HEADER_TIME_STRINGIFY

#	include <chrono>
#	include <string>
#	include "../concepts/duration.hpp"
#	include "../concepts/string.hpp"
#	include "../math/stringify.hpp"
#	include "../strings/pad_front.hpp"

namespace xieite::time {
	template<xieite::concepts::String String = std::string, xieite::concepts::Duration Duration>
	[[nodiscard]] constexpr String stringify(Duration value, const bool date = true, const bool time = true, const bool subsecond = false) noexcept {
		const std::chrono::years years = std::chrono::duration_cast<std::chrono::years>(value);
		value -= std::chrono::duration_cast<Duration>(years);
		const std::chrono::months months = std::chrono::duration_cast<std::chrono::months>(value);
		value -= std::chrono::duration_cast<Duration>(months);
		const std::chrono::days days = std::chrono::duration_cast<std::chrono::days>(value);
		value -= std::chrono::duration_cast<Duration>(days);
		const std::chrono::hours hours = std::chrono::duration_cast<std::chrono::hours>(value);
		value -= std::chrono::duration_cast<Duration>(hours);
		const std::chrono::minutes minutes = std::chrono::duration_cast<std::chrono::minutes>(value);
		value -= std::chrono::duration_cast<Duration>(minutes);
		const std::chrono::seconds seconds = std::chrono::duration_cast<std::chrono::seconds>(value);
		value -= std::chrono::duration_cast<Duration>(seconds);
		const std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(value);
		value -= std::chrono::duration_cast<Duration>(milliseconds);
		const std::chrono::microseconds microseconds = std::chrono::duration_cast<std::chrono::microseconds>(value);
		value -= std::chrono::duration_cast<Duration>(microseconds);
		const std::chrono::nanoseconds nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(value);
		String result;
		if (date) {
			result += xieite::math::stringify<String>(years.count()) + '-' + xieite::strings::padFront(xieite::math::stringify<String>(months.count()), 2, '0') + '-' + xieite::strings::padFront(xieite::math::stringify<String>(days.count()), 2, '0');
		}
		if (time) {
			if (date) {
				result += ' ';
			}
			result += xieite::strings::padFront(xieite::math::stringify<String>(hours.count()), 2, '0') + ':' + xieite::strings::padFront(xieite::math::stringify<String>(minutes.count()), 2, '0') + ':' + xieite::strings::padFront(xieite::math::stringify<String>(seconds.count()), 2, '0');
		}
		if (subsecond) {
			if (date || time) {
				result += ' ';
			}
			result += xieite::strings::padFront(xieite::math::stringify<String>(milliseconds.count()), 4, '0') + ':' + xieite::strings::padFront(xieite::math::stringify<String>(microseconds.count()), 4, '0') + ':' + xieite::strings::padFront(xieite::math::stringify<String>(nanoseconds.count()), 4, '0');
		}
		return result;
	}
}

#endif
