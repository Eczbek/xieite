#ifndef XIEITE_HEADER_MATH_FACTORIAL
#	define XIEITE_HEADER_MATH_FACTORIAL

#include <array>
#include <cstddef>
#include <vector>

namespace xieite::math {
	[[nodiscard]] constexpr std::size_t factorial(const std::size_t value) noexcept {
		static constexpr auto generate = [] {
			std::vector<std::size_t> result { 1 };
			for (std::size_t i = 1; !xieite::math::multiplicationOverflows(i, result[i - 1]); ++i) {
				result.push_back(i * result[i - 1]);
			}
			return result;
		};
		static constexpr auto lookup = xieite::containers::makeArray<std::size_t, generate().size()>(generate());
		return lookup.at(value);
	}
}

#endif
