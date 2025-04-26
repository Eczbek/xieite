#ifndef DETAIL_XIEITE_HEADER_FN_FSTR_UDL
#	define DETAIL_XIEITE_HEADER_FN_FSTR_UDL
#
#	include "../data/fixed_str.hpp"

namespace xieite::fstr_udl {
	template<xieite::fixed_str fstr>
	[[nodiscard]] consteval auto operator""_fstr() noexcept {
		return fstr;
	}
}

#endif
