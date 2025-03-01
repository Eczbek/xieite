#pragma once

#include <cstddef>
#include <type_traits>
#include "../trait/cpref.hpp"

namespace x4 {
	template<typename T, std::size_t n = 1>
	using addptr = decltype(([]<typename U = T, std::size_t m = n>(this auto self) {
		if constexpr (m) {
			return self.template operator()<x4::cpref<U, std::remove_reference_t<U>*>, (m - 1)>();
		} else {
			return std::type_identity<U>();
		}
	})())::type;
}
