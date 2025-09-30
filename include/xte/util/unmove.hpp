#ifndef DETAIL_XTE_HEADER_UTIL_UNMOVE
#	define DETAIL_XTE_HEADER_UTIL_UNMOVE

namespace xte {
	template<typename T>
	[[nodiscard]] constexpr T& unmove(T&& x = {}) noexcept {
		return { x };
	}
}

#endif
