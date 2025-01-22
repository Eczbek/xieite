export module xieite:rm_ptr;

import std;
import :cp_ref;
import :is_ptr;
import :rm_ref;
import :t;

export namespace xieite {
	template<typename T, std::size_t n = 1>
	using rm_ptr = xieite::cp_ref<T, typename decltype(([]<typename U = xieite::rm_ref<T>, std::size_t m = n>(this auto self) {
		if constexpr (xieite::is_ptr<U> && m) {
			return self.template operator()<std::remove_pointer_t<T>, (m - 1)>();
		} else {
			return xieite::t<U>();
		}
	})())::type>;
}
