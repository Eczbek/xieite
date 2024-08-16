#ifndef XIEITE_HEADER_MATH_FACTORIAL
#	define XIEITE_HEADER_MATH_FACTORIAL

#	include <cstddef>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../containers/make_array.hpp"
#	include "../math/multiplication_overflows.hpp"

namespace xieite::detail {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr std::vector<Arithmetic> generateFactorial() noexcept {
		std::vector<Arithmetic> result = { 1 };
		for (Arithmetic i = 1; !xieite::math::multiplicationOverflows(i, result[i - 1]); ++i) {
			result.push_back(i * result[i - 1]);
		}
		return result;
	}
}

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	inline constexpr std::array<Arithmetic, xieite::detail::generateFactorial<Arithmetic>().size()> factorial = xieite::containers::makeArray<Arithmetic, xieite::detail::generateFactorial<Arithmetic>().size()>(xieite::detail::generateFactorial<Arithmetic>());
}

#endif
