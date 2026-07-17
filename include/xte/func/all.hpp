#ifndef DETAIL_XTE_HEADER_FUNC_ALL
#	define DETAIL_XTE_HEADER_FUNC_ALL
#
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <functional>

namespace xte {
	[[nodiscard]] constexpr auto all(auto&& func, auto&&... args) XTE_RETURNS(
		(... && std::invoke_r<bool>(func, XTE_FWD(args)))
	);
}

#endif
