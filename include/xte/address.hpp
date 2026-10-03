#ifndef DETAIL_XTE_HEADER_UTIL_ADDRESS
#	define DETAIL_XTE_HEADER_UTIL_ADDRESS
#
#	include <memory>

namespace xte {
	inline constexpr auto address = [][[nodiscard]](auto& x) static noexcept {
		return std::addressof(x);
	};
}

#endif
