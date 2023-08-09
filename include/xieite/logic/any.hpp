#ifndef XIEITE_HEADER__LOGIC__ANY
#	define XIEITE_HEADER__LOGIC__ANY

#	include <concepts>
#	include <type_traits>

namespace xieite::logic {
	template<std::convertible_to<bool>... Values>
	constexpr bool any(const Values&... values)
	noexcept(noexcept((std::is_nothrow_convertible_v<Values, bool> && ...))) {
		return (static_cast<bool>(values) || ...);
	}
}

#endif
