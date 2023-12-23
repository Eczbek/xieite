#ifndef XIEITE_HEADER_MATH_FIBONACCI
#	define XIEITE_HEADER_MATH_FIBONACCI

#include <cstddef>
#include <vector>
#include "../containers/make_array.hpp"
#include "../math/addition_overflows.hpp"

namespace xieite::math {
	inline constexpr auto fibonacci = ([] {
		static constexpr auto generate = [] {
			std::vector<std::size_t> result { 0, 1 };
			for (std::size_t i = 2; !xieite::math::additionOverflows(result[i - 1], result[i - 2]); ++i) {
				result.push_back(result[i - 1] + result[i - 2]);
			}
			return result;
		};
		return xieite::containers::makeArray<std::size_t, generate().size()>(generate());
	})();
}

#endif
