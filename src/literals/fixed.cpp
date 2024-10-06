export module xieite:literals.fixed;

import :containers.FixedString;

export namespace xieite::literals::fixed {
	template<xieite::containers::FixedString string>
	[[nodiscard]] constexpr auto operator""_fixed() noexcept {
		return string;
	}
}
