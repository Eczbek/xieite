#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_AGGREGATE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_AGGREGATE
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_aggregate = std::is_aggregate_v<T>;
}

#endif
