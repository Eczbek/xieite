#ifndef DETAIL_XIEITE_HEADER_FN_FIXED_STR_LIT
#	define DETAIL_XIEITE_HEADER_FN_FIXED_STR_LIT
#
#	include "../ctnr/fixed_str.hpp"

namespace xieite::fixed_str_lit {
	template<xieite::fixed_str fstr>
	[[nodiscard]] consteval auto operator""_fstr() noexcept {
		return fstr;
	}
}

#endif
