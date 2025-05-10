#ifndef DETAIL_XIEITE_HEADER_MATH_SPLIT_BOOL
#	define DETAIL_XIEITE_HEADER_MATH_SPLIT_BOOL
#
#	include "../math/ssize_t.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith = xieite::ssize_t>
	[[nodiscard]] constexpr Arith split_bool(bool x) noexcept {
		return static_cast<Arith>(x * 2 - 1);
	}
}

#endif
