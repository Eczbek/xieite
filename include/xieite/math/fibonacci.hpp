#ifndef XIEITE_HEADER_MATH_FIBONACCI
#	define XIEITE_HEADER_MATH_FIBONACCI

#	include <cstddef>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../containers/make_array.hpp"
#	include "../math/addition_overflows.hpp"

namespace xieite::detail {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr std::vector<Arithmetic_> generateFibonacci() noexcept {
		std::vector<Arithmetic_> result = { 0, 1 };
		for (std::size_t i = 2; !xieite::math::additionOverflows(result[i - 1], result[i - 2]); ++i) {
			result.push_back(result[i - 1] + result[i - 2]);
		}
		return result;
	}
}

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	inline constexpr auto fibonacci = xieite::containers::makeArray<Arithmetic_, xieite::detail::generateFibonacci<Arithmetic_>().size()>(xieite::detail::generateFibonacci<Arithmetic_>());
}

#endif
