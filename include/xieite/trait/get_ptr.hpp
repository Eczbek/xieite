#pragma once

#include <cstddef>
#include "../trait/is_ptr.hpp"
#include "../trait/rm_ptr.hpp"

namespace xieite {
	template<typename T>
	inline constexpr std::size_t get_ptr = ([]<typename U = T>(this auto self) -> std::size_t {
		if constexpr (xieite::is_ptr<U>) {
			return 1 + self.template operator()<xieite::rm_ptr<U>>();
		} else {
			return 0;
		}
	})();
}
