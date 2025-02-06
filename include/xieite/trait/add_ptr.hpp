#pragma once

#include <cstddef>
#include <type_traits>
#include "../trait/cp_ref.hpp"

namespace xieite {
	template<typename T, std::size_t n = 1>
	using add_ptr = decltype(([]<typename U = T, std::size_t m = n>(this auto self) {
		if constexpr (m) {
			return self.template operator()<xieite::cp_ref<U, std::remove_reference_t<U>*>, (m - 1)>();
		} else {
			return std::type_identity<U>();
		}
	})())::type;
}
