#ifndef DETAIL_XTE_HEADER_UTIL_LVALUE
#	define DETAIL_XTE_HEADER_UTIL_LVALUE

namespace xte {
	inline constexpr auto lvalue = [][[nodiscard]](auto&& x) static noexcept -> decltype(x)& {
		return { x };
	};
}

#endif
