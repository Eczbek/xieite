#ifndef DETAIL_XIEITE_HEADER_FN_FSTR
#	define DETAIL_XIEITE_HEADER_FN_FSTR
#
#	include "../ctnr/fixed_str.hpp"

namespace xieite::_fstr {
	template<xieite::fixed_str fstr>
	[[nodiscard]] consteval auto operator""_fstr() noexcept {
		return fstr;
	}
}

#endif
