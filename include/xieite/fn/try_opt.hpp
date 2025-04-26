#ifndef DETAIL_XIEITE_HEADER_FN_TRY_OPT
#	define DETAIL_XIEITE_HEADER_FN_TRY_OPT
#
#	include <functional>
#	include <optional>
#	include "../pp/arrow.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto try_opt(auto&& fn, auto&&... args)
		XIEITE_ARROW_TRY(std::optional(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...)),, std::nullopt)
}

#endif
