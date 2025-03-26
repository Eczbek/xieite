#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_INT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_INT
#
#	include <concepts>
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_int = std::integral<T> && !std::same_as<std::remove_cv_t<T>, bool>;
}

#endif
