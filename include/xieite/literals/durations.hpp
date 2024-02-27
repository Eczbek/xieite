#ifndef XIEITE_HEADER_LITERALS_DURATIONS
#	define XIEITE_HEADER_LITERALS_DURATIONS

#	include "../time/durations.hpp"

namespace xieite::literals::durations {
	[[nodiscard]] constexpr xieite::time::durations::Decades operator""_decades(const unsigned long long int value) noexcept {
		return xieite::time::durations::Decades(value);
	}

	[[nodiscard]] constexpr xieite::time::durations::Decades operator""_decades(const long double value) noexcept {
		return xieite::time::durations::Decades(value);
	}

	[[nodiscard]] constexpr xieite::time::durations::Centuries operator""_centuries(const unsigned long long int value) noexcept {
		return xieite::time::durations::Centuries(value);
	}

	[[nodiscard]] constexpr xieite::time::durations::Centuries operator""_centuries(const long double value) noexcept {
		return xieite::time::durations::Centuries(value);
	}

	[[nodiscard]] constexpr xieite::time::durations::Millenniums operator""_millenniums(const unsigned long long int value) noexcept {
		return xieite::time::durations::Millenniums(value);
	}

	[[nodiscard]] constexpr xieite::time::durations::Millenniums operator""_millenniums(const long double value) noexcept {
		return xieite::time::durations::Millenniums(value);
	}

	[[nodiscard]] constexpr xieite::time::durations::Epochs operator""_epochs(const unsigned long long int value) noexcept {
		return xieite::time::durations::Epochs(value);
	}

	[[nodiscard]] constexpr xieite::time::durations::Epochs operator""_epochs(const long double value) noexcept {
		return xieite::time::durations::Epochs(value);
	}

	[[nodiscard]] constexpr xieite::time::durations::Eons operator""_eons(const unsigned long long int value) noexcept {
		return xieite::time::durations::Eons(value);
	}

	[[nodiscard]] constexpr xieite::time::durations::Eons operator""_eons(const long double value) noexcept {
		return xieite::time::durations::Eons(value);
	}
}

#endif
