export module xieite:algorithms.rotate;

import std;
import :concepts.Constant;

export namespace xieite::algorithms {
	template<typename Type, typename... Types>
	requires(!xieite::concepts::Constant<Type> && (... && !xieite::concepts::Constant<Types>))
	constexpr void rotate(std::size_t distance, Type& first, Types&... rest) noexcept {
		distance %= sizeof...(Types) + 1;
		while (distance--) {
			Type last = std::move(first);
			([](this auto self, auto& first, auto& second, auto&... rest) -> void {
				first = std::move(second);
				if constexpr (sizeof...(rest)) {
					self(second, rest...);
				}
			})(first, rest..., last);
		}
	}
}
