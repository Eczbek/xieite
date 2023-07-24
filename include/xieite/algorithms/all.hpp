#ifndef XIEITE_HEADER_ALGORITHMS_ALL
#	define XIEITE_HEADER_ALGORITHMS_ALL

#	include <concepts>
#	include <type_traits>

namespace xieite::algorithms {
	template<std::convertible_to<bool>... Booleanables>
	[[nodiscard]]
	constexpr bool all(const Booleanables&... values)
	noexcept(noexcept((std::is_nothrow_convertible_v<Booleanables, bool> && ...))) {
		return (static_cast<bool>(values) && ...);
	}
}

#endif
