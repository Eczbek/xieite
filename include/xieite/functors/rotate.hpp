#ifndef XIEITE_HEADER_FUNCTORS_ROTATE
#	define XIEITE_HEADER_FUNCTORS_ROTATE

#	include <utility>
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename Type, typename... Types>
	constexpr void rotate(Type& first, Types&... rest) noexcept {
		Type last = std::move(first);
		([]<typename Self, typename First, typename Second, typename... Rest>(this Self&& self, First& first, Second& second, Rest&... rest) -> void {
			first = std::move(second);
			if constexpr (sizeof...(Rest)) {
				XIEITE_FORWARD(self)(second, rest...);
			}
		})(first, rest..., last);
	}
}

#endif
