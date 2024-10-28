export module xieite:rotate;

import std;

export namespace xieite {
	template<typename T, typename... Ts>
	requires(!std::is_const_v<T> && (... && !std::is_const_v<Ts>))
	constexpr void rotate(std::size_t distance, T& first, Ts&... rest) noexcept {
		distance %= sizeof...(Ts) + 1;
		while (distance--) {
			T last = std::move(first);
			([](this auto self, auto& first, auto& second, auto&... rest) {
				first = std::move(second);
				if constexpr (sizeof...(rest) > 0) {
					self(second, rest...);
				}
			})(first, rest..., last);
		}
	}
}
