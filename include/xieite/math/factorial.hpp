#ifndef XIEITE_HEADER_MATH_FACTORIAL
#	define XIEITE_HEADER_MATH_FACTORIAL

#	include <cstddef>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../containers/make_array.hpp"
#	include "../math/multiplication_overflows.hpp"

namespace xieite::detail {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr std::vector<Arithmetic_> generateFactorial() noexcept {
		std::vector<Arithmetic_> result = { 1 };
		for (Arithmetic_ i = 1; !xieite::math::multiplicationOverflows(i, result[i - 1]); ++i) {
			result.push_back(i * result[i - 1]);
		}
		return result;
	}
}

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	inline constexpr std::array<Arithmetic_, xieite::detail::generateFactorial<Arithmetic_>().size()> factorial = xieite::containers::makeArray<Arithmetic_, xieite::detail::generateFactorial<Arithmetic_>().size()>(xieite::detail::generateFactorial<Arithmetic_>());
}

#endif
