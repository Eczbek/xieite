#ifndef DETAIL_XTE_HEADER_FUNC_NOOP
#	define DETAIL_XTE_HEADER_FUNC_NOOP
#
#	include "../preproc/fwd.hpp"

namespace xte {
	inline constexpr auto noop = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return XTE_FWD(x);
	};
}

#endif
