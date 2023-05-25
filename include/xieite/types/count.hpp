#ifndef XIEITE_HEADER_TYPES_COUNT
#	define XIEITE_HEADER_TYPES_COUNT

#	include <cstddef>

namespace xieite::types {
	template<typename... Any>
	inline constexpr std::size_t count = sizeof...(Any);
}

#endif
