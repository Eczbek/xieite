#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_UNSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_UNSIGN
#
#	include "../trait/is_arith.hpp"
#	include "../trait/try_unsign.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr auto as_unsign(T x) noexcept {
		return static_cast<xieite::try_unsign<T>>(x);
	}
}

#endif
