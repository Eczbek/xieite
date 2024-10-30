module;

#include <xieite/fwd.hpp>

export module xieite:dist_args_recurs;

import std;
import :tuple_splice;
import :unroll;
import :any;
import :type_list;

export namespace xieite {
	template<std::size_t arity, std::size_t prev_idx = 0, typename F, typename... Args>
	requires(xieite::type_list<xieite::any>::template repeat<arity>::template prepend<F>::template to<std::is_invocable>::value)
	constexpr decltype(auto) dist_args_recurs(F&& fn, Args&&... args)
	noexcept(xieite::type_list<xieite::any>::template repeat<arity>::template prepend<F>::template to<std::is_nothrow_invocable>::value) {
		static_assert(prev_idx < arity, "index of previous result must be within functor arity");
		static_assert((arity > 1) || !sizeof...(Args), "arguments must be distributable across functor calls");
		static_assert(sizeof...(Args) >= arity, "number of arguments must not be less than functor arity");
		if constexpr (sizeof...(Args) == arity) {
			return std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...);
		} else {
			const std::tuple<Args&&...> args_tuple = std::forward_as_tuple(XIEITE_FWD(args)...);
			const auto result = xieite::tuple_splice<prev_idx + arity>(args_tuple, std::forward_as_tuple(std::apply(fn, xieite::tuple_splice<arity, sizeof...(Args) - arity>(args_tuple))));
			return xieite::unroll<sizeof...(Args) - arity + 1>([&fn, &result]<std::size_t... i> {
				return xieite::dist_args_recurs<arity, prev_idx>(XIEITE_FWD(fn), std::get<i + arity>(std::move(result))...);
			});
		}
	}
}
