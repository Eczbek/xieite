#ifndef DETAIL_XTE_HEADER_UTIL_ADDRESS
#	define DETAIL_XTE_HEADER_UTIL_ADDRESS
#
#	include "../trait/add_ptr.hpp"
#	include <memory>

namespace xte {
	inline constexpr auto address = [][[nodiscard]](auto& x) static noexcept -> xte::add_ptr<decltype(x)> {
		return std::addressof(x);
	};
}

#endif
