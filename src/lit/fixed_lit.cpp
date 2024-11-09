export module xieite:fixed_lit;

import :fixed_str;

export namespace xieite::fixed_lit {
	template<xieite::fixed_str str>
	[[nodiscard]] constexpr auto operator""_fixed() noexcept {
		return str;
	}
}
