#pragma once

#include <cstddef>
#include <vector>
#include "../ctnr/mkarr.hpp"
#include "../math/mulovf.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	constexpr auto fctrl = ([] static {
		static constexpr auto get = [] static -> std::vector<T> {
			std::vector<T> result = { 1 };
			for (std::size_t i = 1; !x4::mulovf(static_cast<T>(i), result[i - 1]); ++i) {
				result.push_back(static_cast<T>(i) * result[i - 1]);
			}
			return result;
		};
		return x4::mkarr<T, get().size()>(get());
	})();
}
