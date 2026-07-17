#ifndef DETAIL_XTE_HEADER_UTIL_AS_LVALUE
#	define DETAIL_XTE_HEADER_UTIL_AS_LVALUE

namespace xte {
	inline constexpr auto as_lvalue = [][[nodiscard]](auto&& x) static noexcept -> decltype(x)& {
		return { x };
	};
}

#endif
