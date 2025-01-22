export module xieite:fixed_str_lit;

import :fixed_str;

export namespace xieite::fixed_str_lit {
	template<xieite::fixed_str fstr>
	[[nodiscard]] constexpr auto operator""_fstr() noexcept {
		return fstr;
	}
}
