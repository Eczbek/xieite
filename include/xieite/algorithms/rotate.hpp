#ifndef XIEITE_HEADER_ALGORITHMS_ROTATE
#	define XIEITE_HEADER_ALGORITHMS_ROTATE

#	include <cstddef>
#	include <utility>
#	include "../concepts/constant.hpp"
#	include "../macros/forward.hpp"

namespace xieite::algorithms {
	template<typename Type_, typename... Types_>
	requires(!xieite::concepts::Constant<Type_> && (... && !xieite::concepts::Constant<Types_>))
	constexpr void rotate(std::size_t distance, Type_& first, Types_&... rest) noexcept {
		distance %= sizeof...(Types_) + 1;
		while (distance--) {
			Type_ last = std::move(first);
			([](this auto&& self, auto& first, auto& second, auto&... rest) {
				first = std::move(second);
				if constexpr (sizeof...(rest)) {
					XIEITE_FORWARD(self)(second, rest...);
				}
			})(first, rest..., last);
		}
	}
}

#endif
