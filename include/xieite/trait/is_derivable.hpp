#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DERIVABLE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DERIVABLE
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_derivable = !std::is_final_v<T>;
}

#endif
