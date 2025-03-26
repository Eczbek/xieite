#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_POLYMORPHIC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_POLYMORPHIC
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_polymorphic = std::is_polymorphic_v<T>;
}

#endif
