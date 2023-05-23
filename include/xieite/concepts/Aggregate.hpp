#ifndef XIEITE_HEADER_CONCEPTS_AGGREGATE
#	define XIEITE_HEADER_CONCEPTS_AGGREGATE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Aggregate = std::is_aggregate_v<Any>;
}

#endif
