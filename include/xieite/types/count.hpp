#ifndef XIEITE_HEADER__TYPES__COUNT
#	define XIEITE_HEADER__TYPES__COUNT

#	include <cstddef>

namespace xieite::types {
	template<typename... Any>
	inline constexpr std::size_t count = sizeof...(Any);
}

#endif
