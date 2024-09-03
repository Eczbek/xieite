export module xieite:strings.between;

import std;
import :strings.after;
import :strings.before;

export namespace xieite::strings {
	[[nodiscard]] constexpr std::string_view between(const std::string_view string, const std::string_view start, const std::string_view end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	[[nodiscard]] constexpr std::string_view between(const std::string_view string, const std::string_view start, const char end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	[[nodiscard]] constexpr std::string_view between(const std::string_view string, const char start, const std::string_view end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}

	[[nodiscard]] constexpr std::string_view between(const std::string_view string, const char start, const char end) noexcept {
		return xieite::strings::before(xieite::strings::after(string, start), end);
	}
}
