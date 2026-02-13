#ifndef DETAIL_XTE_HEADER_FUNC_NOP
#	define DETAIL_XTE_HEADER_FUNC_NOP
#
#	include "../preproc/fwd.hpp"

namespace xte {
	inline constexpr auto nop = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return XTE_FWD(x);
	};
}

#endif
