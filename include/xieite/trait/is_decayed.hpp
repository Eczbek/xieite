#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DECAYED
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DECAYED
#
#	include <concepts>
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_decayed = std::same_as<T, std::decay_t<T>>;
}

#endif
