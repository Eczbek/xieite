#ifndef XIEITE_HEADER_MATH_FACTORIAL
#	define XIEITE_HEADER_MATH_FACTORIAL

#	include <array>
#	include <cstddef>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../math/multiplication_overflows.hpp"
#	include "../ranges/make_array.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	inline constexpr auto factorial = ([] {
		static constexpr auto generate = [] {
			std::vector<Number> result = { 1 };
			for (Number i = 1; !xieite::math::multiplicationOverflows(i, result[i - 1]); ++i) {
				result.push_back(i * result[i - 1]);
			}
			return result;
		};
		return xieite::ranges::makeArray<Number, generate().size()>(generate());
	})();
}

#endif
