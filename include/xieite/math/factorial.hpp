#pragma once

#include <cstddef>
#include <vector>
#include "../ctnr/make_array.hpp"
#include "../math/mul_overflow.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	inline constexpr auto factorial = ([] {
		static constexpr auto get = [] -> std::vector<T> {
			std::vector<T> result = { 1 };
			for (std::size_t i = 1; !xieite::mul_overflow(static_cast<T>(i), result[i - 1]); ++i) {
				result.push_back(static_cast<T>(i) * result[i - 1]);
			}
			return result;
		};
		return xieite::make_array<T, get().size()>(get());
	})();
}
