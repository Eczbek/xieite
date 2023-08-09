#ifndef XIEITE_HEADER__TYPES__COUNT
#	define XIEITE_HEADER__TYPES__COUNT

#	include <cstddef>

namespace xieite::types {
	template<typename... Types>
	inline constexpr std::size_t count = sizeof...(Types);
}

#endif
