#ifndef DETAIL_XIEITE_HEADER_MATH_CLOSEST
#	define DETAIL_XIEITE_HEADER_MATH_CLOSEST
#
#	include <concepts>
#	include "../math/diff.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, std::convertible_to<Arith>... Ariths>
	[[nodiscard]] constexpr Arith closest(Arith target, Arith first, Ariths... rest) noexcept {
		Arith result = first;
		(..., (result = (xieite::diff(target, rest) < xieite::diff(target, result)) ? rest : result));
		return result;
	}
}

#endif
