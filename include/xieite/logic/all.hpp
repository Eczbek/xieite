#ifndef XIEITE_HEADER__LOGIC__ALL
#	define XIEITE_HEADER__LOGIC__ALL

#	include <concepts>
#	include "../concepts/NoThrowConvertibleToAllOf.hpp"

namespace xieite::logic {
	template<std::convertible_to<bool>... Values>
	constexpr bool all(const Values&... values)
	noexcept(noexcept(xieite::concepts::NoThrowConvertibleToAllOf<bool, Values...>)) {
		return (... && static_cast<bool>(values));
	}
}

#endif
