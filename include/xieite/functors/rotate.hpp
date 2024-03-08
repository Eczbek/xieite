#ifndef XIEITE_HEADER_FUNCTORS_ROTATE
#	define XIEITE_HEADER_FUNCTORS_ROTATE

#	include <cstddef>
#	include <type_traits>
#	include <utility>
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename Type, typename... Types>
	requires(!std::is_const_v<Type> && (... && !std::is_const_v<Types>))
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
