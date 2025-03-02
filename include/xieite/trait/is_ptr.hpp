#pragma once

#include <cstddef>
#include <type_traits>

namespace DETAIL_XIEITE::is_ptr {
	// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=118620
	template<typename T, std::size_t depth>
	constexpr bool impl = ([]<typename U = std::remove_reference_t<T>, std::size_t curr = depth>(this auto self) -> bool {
		if constexpr (static constexpr bool ptr = std::is_pointer_v<U>; ptr && curr) {
			return self.template operator()<std::remove_pointer_t<U>, (curr - 1)>();
		} else {
			return ptr;
		}
	})();
}

namespace xieite {
	template<typename T, std::size_t depth = 0>
	concept is_ptr = DETAIL_XIEITE::is_ptr::impl<T, depth>;
}
