#ifndef DETAIL_XIEITE_HEADER_MATH_CLOSEST
#	define DETAIL_XIEITE_HEADER_MATH_CLOSEST
#
#	include <concepts>
#	include "../math/diff.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Us>
	[[nodiscard]] constexpr T closest(T target, T first, Us... rest) noexcept {
		T result = first;
		(..., (result = (xieite::diff(target, rest) < xieite::diff(target, result)) ? rest : result));
		return result;
	}
}

#endif
