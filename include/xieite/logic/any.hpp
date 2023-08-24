#ifndef XIEITE_HEADER__LOGIC__ANY
#	define XIEITE_HEADER__LOGIC__ANY

#	include <concepts>
#	include "../concepts/NoThrowConvertibleToAllOf.hpp"

namespace xieite::logic {
	template<std::convertible_to<bool>... Values>
	constexpr bool any(const Values&... values)
	noexcept(noexcept(xieite::concepts::NoThrowConvertibleToAllOf<bool, Values...>)) {
		return (static_cast<bool>(values) || ...);
	}
}

#endif
