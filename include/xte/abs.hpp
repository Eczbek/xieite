#ifndef DETAIL_XTE_HEADER_ABS
#	define DETAIL_XTE_HEADER_ABS
#
#	include "./fundamental_traits.hpp"
#	include "./math/float.hpp"
#	include "./meta/end.hpp"

namespace xte {
	template<xte::is_arithmetic value_type, xte::end...,
		typename unsigned_type = xte::try_unsigned<value_type>>
	[[nodiscard]] constexpr unsigned_type abs(value_type value) noexcept {
		return xte::is_neg(value) ? -static_cast<unsigned_type>(value) : static_cast<unsigned_type>(value);
	}
}

#endif
