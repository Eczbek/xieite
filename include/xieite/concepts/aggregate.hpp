#ifndef XIEITE_HEADER_CONCEPTS_AGGREGATE
#	define XIEITE_HEADER_CONCEPTS_AGGREGATE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Aggregate = std::is_aggregate_v<Type>;
}

#endif
