#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_FINAL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_FINAL
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_final = std::is_final_v<T>;
}

#endif
