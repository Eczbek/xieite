#ifndef DETAIL_XIEITE_HEADER_MATH_SIGN
#	define DETAIL_XIEITE_HEADER_MATH_SIGN
#
#	include "../math/neg.hpp"
#	include "../math/split_bool.hpp"
#	include "../math/ssize_t.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr xieite::ssize_t sign(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		return (xieite::split_bool(!xieite::neg(first)) * ... * xieite::split_bool(!xieite::neg(rest)));
	}
}

#endif
