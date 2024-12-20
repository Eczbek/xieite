module;

#include <xieite/fwd.hpp>

export module xieite:distr_args;

import std;
import :any;
import :end;
import :type_list;
import :unroll;

export namespace xieite {
	template<std::size_t arity, typename F, typename... Args,
		xieite::end...,
		typename List = xieite::type_list<xieite::any>::template repeat<arity>::template prepend<F>>
	requires(List::template to<std::is_invocable>::value)
	constexpr void distr_args(F&& fn, Args&&... args)
	noexcept(List::template to<std::is_nothrow_invocable>::value) {
		static_assert(!!arity || !sizeof...(Args), "arguments must be distributable across functor calls");
		static_assert(sizeof...(Args) >= arity, "number of arguments must not be less than functor arity");
		if constexpr (sizeof...(Args) == arity) {
			std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...);
		} else {
			xieite::unroll<arity>([&fn, &args...]<std::size_t... i> -> void {
				std::invoke(fn, XIEITE_FWD(args...[i])...);
			});
			xieite::unroll<sizeof...(Args) - arity>([&fn, &args...]<std::size_t... i> -> void {
				xieite::distr_args<arity>(XIEITE_FWD(fn), XIEITE_FWD(args...[i + arity])...);
			});
		}
	}
}
