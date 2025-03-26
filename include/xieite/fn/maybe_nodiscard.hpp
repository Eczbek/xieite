#ifndef DETAIL_XIEITE_HEADER_FN_MAYBE_NODISCARD
#	define DETAIL_XIEITE_HEADER_FN_MAYBE_NODISCARD
#
#	include <concepts>
#	include <functional>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<bool cond, typename F, typename... Args>
	requires(!cond && std::invocable<F, Args...>)
	constexpr auto maybe_nodiscard(F&& fn, Args&&... args)
		XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...))

	template<bool cond, typename F, typename... Args>
	requires(cond && std::invocable<F, Args...>)
	[[nodiscard]] constexpr auto maybe_nodiscard(F&& fn, Args&&... args)
		XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...))
}

#endif
