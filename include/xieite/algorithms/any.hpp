#ifndef XIEITE_HEADER_ALGORITHMS_ANY
#	define XIEITE_HEADER_ALGORITHMS_ANY

#	include <concepts>
#	include <type_traits>

namespace xieite::algorithms {
	template<std::convertible_to<bool>... Values>
	[[nodiscard]]
	constexpr bool any(const Values&... values)
	noexcept(noexcept((std::is_nothrow_convertible_v<Values, bool> && ...))) {
		return (static_cast<bool>(values) || ...);
	}
}

#endif
