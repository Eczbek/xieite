export module xieite:get_ptr;

import std;
import :is_ptr;
import :rm_ptr;

export namespace xieite {
	template<typename T>
	constexpr std::size_t get_ptr = ([]<typename U = T>(this auto self) -> std::size_t {
		if constexpr (xieite::is_ptr<U>) {
			return 1 + self.template operator()<xieite::rm_ptr<U>>();
		} else {
			return 0;
		}
	})();
}
