#ifndef XIEITE_HEADER_TYPES_COUNT
#	define XIEITE_HEADER_TYPES_COUNT

#	include <cstddef>

namespace xieite::types {
	template<typename... Types>
	inline constexpr std::size_t count = sizeof...(Types);
}

#endif
