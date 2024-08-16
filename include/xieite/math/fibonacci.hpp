#ifndef XIEITE_HEADER_MATH_FIBONACCI
#	define XIEITE_HEADER_MATH_FIBONACCI

#	include <cstddef>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../containers/make_array.hpp"
#	include "../math/addition_overflows.hpp"

namespace xieite::detail {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr std::vector<Arithmetic> generateFibonacci() noexcept {
		std::vector<Arithmetic> result = { 0, 1 };
		for (std::size_t i = 2; !xieite::math::additionOverflows(result[i - 1], result[i - 2]); ++i) {
			result.push_back(result[i - 1] + result[i - 2]);
		}
		return result;
	}
}

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	inline constexpr auto fibonacci = xieite::containers::makeArray<Arithmetic, xieite::detail::generateFibonacci<Arithmetic>().size()>(xieite::detail::generateFibonacci<Arithmetic>());
}

#endif
