#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CLASS
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CLASS
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_class = std::is_class_v<T>;
}

#endif
