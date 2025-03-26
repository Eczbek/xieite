#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_AGGR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_AGGR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_aggr = std::is_aggregate_v<T>;
}

#endif
