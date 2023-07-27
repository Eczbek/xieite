#ifndef XIEITE_HEADER_TYPES_UNIQUE
#	define XIEITE_HEADER_TYPES_UNIQUE

#	include <type_traits>
#	include "../types/List.hpp"

namespace xieite::types {
	template<typename... Types>
	using Unique = decltype((xieite::types::List<>()->*...->*xieite::types::List<Types>()));
}

// Thanks to Eisenwave for original code

#endif
