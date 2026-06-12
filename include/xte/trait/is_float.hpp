#ifndef DETAIL_XTE_HEADER_TRAIT_IS_FLOAT
#	define DETAIL_XTE_HEADER_TRAIT_IS_FLOAT
#
#	include <concepts>

namespace xte {
	template<typename T>
	concept is_float = std::floating_point<T>;
}

#endif
