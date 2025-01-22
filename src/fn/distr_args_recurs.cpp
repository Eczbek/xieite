module;

#include <xieite/fwd.hpp>

export module xieite:distr_args_recurs;

import std;
import :splice_tuple;
import :unroll;

export namespace xieite {
	template<std::size_t arity, std::size_t prev_idx = 0, typename F, typename... Args>
	constexpr decltype(auto) distr_args_recurs(F&& fn, Args&&... args) noexcept(false) {
		static_assert(prev_idx < arity, "index of previous result must be within functor arity");
		static_assert((arity > 1) || !sizeof...(Args), "arguments must be distributable across functor calls");
		static_assert(sizeof...(Args) >= arity, "number of arguments must not be less than functor arity");
		if constexpr (sizeof...(Args) == arity) {
			return std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...);
		} else {
			const auto args_tuple = std::forward_as_tuple(XIEITE_FWD(args)...);
			const auto result = xieite::splice_tuple<prev_idx + arity>(args_tuple, std::forward_as_tuple(std::apply(fn, xieite::splice_tuple<arity, sizeof...(Args) - arity>(args_tuple))));
			return xieite::unroll<sizeof...(Args) - arity + 1>([&fn, &result]<std::size_t... i> -> decltype(auto) {
				return xieite::distr_args_recurs<arity, prev_idx>(XIEITE_FWD(fn), std::get<i + arity>(std::move(result))...);
			});
		}
	}
}
