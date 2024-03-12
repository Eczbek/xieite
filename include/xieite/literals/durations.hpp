#ifndef XIEITE_HEADER_LITERALS_DURATIONS
#	define XIEITE_HEADER_LITERALS_DURATIONS

#	include <chrono>
#	include "../time/centuries.hpp"
#	include "../time/decades.hpp"
#	include "../time/eons.hpp"
#	include "../time/epochs.hpp"
#	include "../time/millenniums.hpp"

namespace xieite::literals::durations {
	[[nodiscard]] constexpr std::chrono::nanoseconds operator""_nanoseconds(const unsigned long long int value) noexcept {
		return std::chrono::nanoseconds(value);
	}

	[[nodiscard]] constexpr std::chrono::microseconds operator""_microseconds(const unsigned long long int value) noexcept {
		return std::chrono::microseconds(value);
	}

	[[nodiscard]] constexpr std::chrono::milliseconds operator""_milliseconds(const unsigned long long int value) noexcept {
		return std::chrono::milliseconds(value);
	}

	[[nodiscard]] constexpr std::chrono::seconds operator""_seconds(const unsigned long long int value) noexcept {
		return std::chrono::seconds(value);
	}

	[[nodiscard]] constexpr std::chrono::minutes operator""_minutes(const unsigned long long int value) noexcept {
		return std::chrono::minutes(value);
	}

	[[nodiscard]] constexpr std::chrono::hours operator""_hours(const unsigned long long int value) noexcept {
		return std::chrono::hours(value);
	}

	[[nodiscard]] constexpr std::chrono::days operator""_days(const unsigned long long int value) noexcept {
		return std::chrono::days(value);
	}

	[[nodiscard]] constexpr std::chrono::weeks operator""_weeks(const unsigned long long int value) noexcept {
		return std::chrono::weeks(value);
	}

	[[nodiscard]] constexpr std::chrono::months operator""_months(const unsigned long long int value) noexcept {
		return std::chrono::months(value);
	}

	[[nodiscard]] constexpr std::chrono::years operator""_years(const unsigned long long int value) noexcept {
		return std::chrono::years(value);
	}

	[[nodiscard]] constexpr xieite::time::Decades operator""_decades(const unsigned long long int value) noexcept {
		return xieite::time::Decades(value);
	}

	[[nodiscard]] constexpr xieite::time::Centuries operator""_centuries(const unsigned long long int value) noexcept {
		return xieite::time::Centuries(value);
	}

	[[nodiscard]] constexpr xieite::time::Millenniums operator""_millenniums(const unsigned long long int value) noexcept {
		return xieite::time::Millenniums(value);
	}

	[[nodiscard]] constexpr xieite::time::Epochs operator""_epochs(const unsigned long long int value) noexcept {
		return xieite::time::Epochs(value);
	}

	[[nodiscard]] constexpr xieite::time::Eons operator""_eons(const unsigned long long int value) noexcept {
		return xieite::time::Eons(value);
	}
}

#endif
