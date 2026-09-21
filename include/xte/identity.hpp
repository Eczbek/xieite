#ifndef DETAIL_XTE_HEADER_IDENTITY
#	define DETAIL_XTE_HEADER_IDENTITY
#
#	include "./preproc/fwd.hpp"

namespace xte {
	inline constexpr auto identity = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return XTE_FWD(x);
	};
}

#endif
