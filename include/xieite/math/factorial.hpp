#ifndef XIEITE_HEADER_MATH_FACTORIAL
#	define XIEITE_HEADER_MATH_FACTORIAL

#	include <cstddef>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../containers/make_array.hpp"
#	include "../math/multiplication_overflows.hpp"

namespace xieite::detail {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::vector<Number> generateFactorial() noexcept {
		std::vector<Number> result = { 1 };
		for (Number i = 1; !xieite::math::multiplicationOverflows(i, result[i - 1]); ++i) {
			result.push_back(i * result[i - 1]);
		}
		return result;
	}
}

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	inline constexpr std::array<Number, xieite::detail::generateFactorial<Number>().size()> factorial = xieite::containers::makeArray<Number, xieite::detail::generateFactorial<Number>().size()>(xieite::detail::generateFactorial<Number>());
}

#endif
