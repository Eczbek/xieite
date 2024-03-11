#ifndef XIEITE_HEADER_ALGORITHMS_ROTATE
#	define XIEITE_HEADER_ALGORITHMS_ROTATE

#	include <cstddef>
#	include <utility>
#	include "../concepts/constant.hpp"
#	include "../macros/forward.hpp"

namespace xieite::algorithms {
	template<typename Type, typename... Types>
	requires(!xieite::concepts::Constant<Type> && (... && !xieite::concepts::Constant<Types>))
	constexpr void rotate(std::size_t distance, Type& first, Types&... rest) noexcept {
		distance %= sizeof...(Types) + 1;
		while (distance--) {
			Type last = std::move(first);
			([]<typename Self, typename First, typename Second, typename... Rest>(this Self&& self, First& first, Second& second, Rest&... rest) -> void {
				first = std::move(second);
				if constexpr (sizeof...(Rest)) {
					XIEITE_FORWARD(self)(second, rest...);
				}
			})(first, rest..., last);
		}
	}
}

#endif
