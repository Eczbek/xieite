#ifndef DETAIL_XIEITE_HEADER_FN_TMP
#	define DETAIL_XIEITE_HEADER_FN_TMP

namespace xieite {
	template<typename T>
	[[nodiscard]] constexpr T& tmp(T&& x = {}) noexcept {
		return { x };
	}
}

#endif
