#ifndef DETAIL_XIEITE_HEADER_FN_NOEX
#	define DETAIL_XIEITE_HEADER_FN_NOEX
#
#	include <concepts>
#	include <functional>
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename Fn, typename... Args>
	requires(std::invocable<Fn, Args...>)
	[[nodiscard]] constexpr decltype(auto) noex(Fn&& fn, Args&&... args) noexcept {
		return std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...);
	}

	template<typename T, typename... Args>
	requires(std::constructible_from<T, Args...>)
	[[nodiscard]] constexpr T noex(Args&&... args) noexcept {
		return T(XIEITE_FWD(args)...);
	}
}

#endif
