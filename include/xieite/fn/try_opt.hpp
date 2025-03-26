#ifndef DETAIL_XIEITE_HEADER_FN_TRY_OPT
#	define DETAIL_XIEITE_HEADER_FN_TRY_OPT
#
#	include <concepts>
#	include <functional>
#	include <optional>
#	include "../pp/arrow.hpp"

namespace xieite {
	template<typename F, typename... Args>
	requires(std::invocable<F, Args...>)
	[[nodiscard]] constexpr auto try_opt(F&& fn, Args&&... args)
		XIEITE_ARROW_TRY(std::optional(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...)),, std::nullopt)
}

#endif
