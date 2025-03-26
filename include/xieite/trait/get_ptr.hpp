#ifndef DETAIL_XIEITE_HEADER_TRAIT_GET_PTR
#	define DETAIL_XIEITE_HEADER_TRAIT_GET_PTR
#
#	include <cstddef>
#	include <type_traits>

namespace xieite {
	template<typename T>
	constexpr std::size_t get_ptr = ([]<typename U = std::remove_reference_t<T>>(this auto self) -> std::size_t {
		if constexpr (std::is_pointer_v<U>) {
			return 1 + self.template operator()<std::remove_pointer_t<U>>();
		} else {
			return 0;
		}
	})();
}

#endif
