#ifndef DETAIL_XIEITE_HEADER_TRAIT_MAYBE_BASE
#	define DETAIL_XIEITE_HEADER_TRAIT_MAYBE_BASE
#
#	include <type_traits>

namespace DETAIL_XIEITE::maybe_base {
	template<typename>
	struct dummy {};
}

namespace xieite {
	template<bool x, typename T>
	using maybe_base = std::conditional_t<x, T, DETAIL_XIEITE::maybe_base::dummy<T>>;
}

#endif
