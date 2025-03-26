#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_SIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_SIGN
#
#	include "../trait/is_arith.hpp"
#	include "../trait/try_sign.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr auto as_sign(T x) noexcept {
		return static_cast<xieite::try_sign<T>>(x);
	}
}

#endif
