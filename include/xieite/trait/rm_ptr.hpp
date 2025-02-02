#pragma once

#include <cstddef>
#include <type_traits>
#include "../meta/t.hpp"
#include "../trait/cp_ref.hpp"

namespace xieite {
	template<typename T, std::size_t n = 1>
	using rm_ptr = xieite::cp_ref<T, typename decltype(([]<typename U = std::remove_reference_t<T>, std::size_t m = n>(this auto self) {
		if constexpr (std::is_pointer_v<U> && m) {
			return self.template operator()<std::remove_pointer_t<U>, (m - 1)>();
		} else {
			return xieite::t<U>();
		}
	})())::type>;
}
