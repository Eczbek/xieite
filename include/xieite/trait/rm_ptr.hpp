#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_PTR
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_PTR
#
#	include <cstddef>
#	include <type_traits>
#	include "../fn/unroll.hpp"
#	include "../meta/fold.hpp"

namespace DETAIL_XIEITE::rm_ptr {
	template<typename T, std::size_t n>
	struct impl : decltype(xieite::unroll<n>([]<std::size_t... i> static {
		return xieite::fold<
			[]<typename U, typename> static {
				return std::remove_pointer<typename U::type>();
			},
			std::remove_reference<T>,
			decltype(i)...
		>();
	})) {};

	template<typename T>
	struct impl<T, -1uz> : decltype(([]<typename U = std::remove_reference_t<T>>(this auto self) {
		if constexpr (std::is_pointer_v<U>) {
			return self.template operator()<std::remove_pointer_t<U>>();
		} else {
			return std::type_identity<U>();
		}
	})()) {};
}

namespace xieite {
	template<typename T, std::size_t n = 1>
	using rm_ptr = DETAIL_XIEITE::rm_ptr::impl<T, n>::type;
}

#endif
