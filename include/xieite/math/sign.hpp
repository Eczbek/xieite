#ifndef DETAIL_XIEITE_HEADER_MATH_SIGN
#	define DETAIL_XIEITE_HEADER_MATH_SIGN
#
#	include "../math/neg.hpp"
#	include "../math/split_bool.hpp"
#	include "../math/ssize_t.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T, xieite::is_arith... Ts>
	[[nodiscard]] constexpr xieite::ssize_t sign(T first, Ts... rest) noexcept {
		return (xieite::split_bool(!xieite::neg(first)) * ... * xieite::split_bool(!xieite::neg(rest)));
	}
}

#endif
