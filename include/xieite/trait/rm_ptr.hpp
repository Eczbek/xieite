#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_PTR
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_PTR
#
#	include <cstddef>
#	include <type_traits>
#	include "../meta/fold_for.hpp"

namespace DETAIL_XIEITE::rm_ptr {
	template<typename T, std::size_t depth>
	struct impl : decltype(xieite::fold_for<
		[]<typename U, auto> static {
			return std::remove_pointer<typename U::type>();
		},
		std::remove_reference<T>,
		depth
	>) {};

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
	template<typename T, std::size_t depth = 1>
	using rm_ptr = DETAIL_XIEITE::rm_ptr::impl<T, depth>::type;
}

#endif
