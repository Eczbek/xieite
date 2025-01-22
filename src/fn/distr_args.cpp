module;

#include <xieite/fwd.hpp>

export module xieite:distr_args;

import std;
import :unroll;

export namespace xieite {
	template<std::size_t arity, typename F, typename... Args>
	constexpr void distr_args(F&& fn, Args&&... args) noexcept(false) {
		static_assert(!!arity || !sizeof...(Args), "arguments must be distributable across functor calls");
		static_assert(sizeof...(Args) >= arity, "number of arguments must not be less than functor arity");
		if constexpr (sizeof...(Args) == arity) {
			std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...);
		} else {
			const auto args_tuple = std::forward_as_tuple(XIEITE_FWD(args)...);
			xieite::unroll<arity>([&fn, &args_tuple]<std::size_t... i> -> void {
				std::invoke(fn, std::get<i>(std::move(args_tuple))...);
			});
			xieite::unroll<sizeof...(Args) - arity>([&fn, &args_tuple]<std::size_t... i> -> void {
				xieite::distr_args<arity>(XIEITE_FWD(fn), std::get<(i + arity)>(std::move(args_tuple))...);
			});
		}
	}
}
