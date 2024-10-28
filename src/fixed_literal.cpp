export module xieite:fixed_literal;

import :fixed_str;

export namespace xieite::fixed_literal {
	template<xieite::fixed_str str>
	[[nodiscard]] constexpr auto operator""_fixed() noexcept {
		return str;
	}
}
