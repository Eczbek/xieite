#ifndef XIEITE_HEADER_TYPES_VALUE
#	define XIEITE_HEADER_TYPES_VALUE

#	include <type_traits>

namespace xieite::types {
	template<auto value>
	struct Value
	: std::integral_constant<decltype(value), value> {};
}

#endif
