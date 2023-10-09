#ifndef XIEITE_HEADER__CONCEPTS__AGGREGATE
#	define XIEITE_HEADER__CONCEPTS__AGGREGATE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Aggregate = std::is_aggregate_v<Type>;
}

#endif
