#ifndef DETAIL_XTE_HEADER_FUNC_ANY
#	define DETAIL_XTE_HEADER_FUNC_ANY
#
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <functional>

namespace xte {
	[[nodiscard]] constexpr auto any(auto&& func, auto&&... args) XTE_RETURNS(
		(... || std::invoke_r<bool>(func, XTE_FWD(args)))
	);
}

#endif
