export module xieite:is_ptr;

import std;

export namespace xieite {
	template<typename T, std::size_t depth = 0>
	concept is_ptr = ([]<typename U = std::remove_reference_t<T>, std::size_t curr = depth>(this auto self) -> bool {
		if constexpr (static constexpr bool ptr = std::is_pointer_v<U>; ptr && curr) {
			return self.template operator()<std::remove_pointer_t<U>, (curr - 1)>();
		} else {
			return ptr;
		}
	})();
}
