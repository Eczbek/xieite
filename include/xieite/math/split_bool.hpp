#ifndef DETAIL_XIEITE_HEADER_MATH_SPLIT_BOOL
#	define DETAIL_XIEITE_HEADER_MATH_SPLIT_BOOL
#
#	include "../math/ssize_t.hpp"

namespace xieite {
	[[nodiscard]] constexpr xieite::ssize_t split_bool(bool x) noexcept {
		return x * 2 - 1;
	}
}

#endif
