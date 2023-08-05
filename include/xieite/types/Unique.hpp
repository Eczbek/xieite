#ifndef XIEITE_HEADER__TYPES__UNIQUE
#	define XIEITE_HEADER__TYPES__UNIQUE

#	include <type_traits>
#	include "../types/List.hpp"

namespace xieite::types {
	template<typename... Types>
	using Unique = decltype((xieite::types::List<>()->*...->*xieite::types::List<Types>()));
}

// Thanks to Eisenwave for original code

#endif
