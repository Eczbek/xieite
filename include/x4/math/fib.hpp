#pragma once

#include <cstddef>
#include <vector>
#include "../ctnr/mkarr.hpp"
#include "../math/addovf.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	constexpr auto fib = ([] static {
		static constexpr auto get = [] static -> std::vector<T> {
			std::vector<T> result = { 0, 1 };
			for (std::size_t i = 2; !x4::addovf(result[i - 1], result[i - 2]); ++i) {
				result.push_back(result[i - 1] + result[i - 2]);
			}
			return result;
		};
		return x4::mkarr<T, get().size()>(get());
	})();
}
