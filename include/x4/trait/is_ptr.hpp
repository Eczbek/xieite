#pragma once

#include <cstddef>
#include <type_traits>

namespace DETAIL_X4::is_ptr {
	template<typename T, std::size_t depth>
	constexpr bool impl = ([]<typename U = std::remove_reference_t<T>, std::size_t curr = depth>(this auto self) -> bool {
		if constexpr (static constexpr bool ptr = std::is_pointer_v<U>; ptr && curr) {
			return self.template operator()<std::remove_pointer_t<U>, (curr - 1)>();
		} else {
			return ptr;
		}
	})();
}

namespace x4 {
	template<typename T, std::size_t depth = 0>
	concept isptr = DETAIL_X4::is_ptr::impl<T, depth>;
}
