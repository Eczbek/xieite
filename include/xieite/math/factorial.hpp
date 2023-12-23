#ifndef XIEITE_HEADER_MATH_FACTORIAL
#	define XIEITE_HEADER_MATH_FACTORIAL

#include <cstddef>
#include <vector>
#include "../containers/make_array.hpp"
#include "../math/multiplication_overflows.hpp"

namespace xieite::math {
	inline constexpr auto factorial = ([] {
		static constexpr auto generate = [] {
			std::vector<std::size_t> result { 1 };
			for (std::size_t i = 1; !xieite::math::multiplicationOverflows(i, result[i - 1]); ++i) {
				result.push_back(i * result[i - 1]);
			}
			return result;
		};
		return xieite::containers::makeArray<std::size_t, generate().size()>(generate());
	})();
}

#endif
