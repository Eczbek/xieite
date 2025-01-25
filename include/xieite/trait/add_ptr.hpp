#pragma once

#include <cstddef>
#include "../meta/t.hpp"
#include "../trait/cp_ref.hpp"
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T, std::size_t n = 1>
	using add_ptr = decltype(([]<typename U = T, std::size_t m = n>(this auto self) {
		if constexpr (m) {
			return self.template operator()<xieite::cp_ref<U, xieite::rm_ref<U>*>, (m - 1)>();
		} else {
			return xieite::t<U>();
		}
	})())::type;
}
