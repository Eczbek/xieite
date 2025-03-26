#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_ABSTRACT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_ABSTRACT
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_abstract = std::is_abstract_v<T>;
}

#endif
