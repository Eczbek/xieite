#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#
#	include <cstddef>

namespace DETAIL_XIEITE::is_bounded_array {
	template<typename, std::size_t>
	constexpr bool impl = false;

	template<typename T, std::size_t n>
	constexpr bool impl<T[n], n> = true;

	template<typename T, std::size_t n>
	constexpr bool impl<T[n], -1uz> = true;
}

namespace xieite {
	template<typename T, std::size_t n = -1uz>
	concept is_bounded_array = DETAIL_XIEITE::is_bounded_array::impl<T, n>;
}

#endif
