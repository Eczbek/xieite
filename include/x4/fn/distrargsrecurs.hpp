#pragma once

#include <cstddef>
#include <functional>
#include <tuple>
#include <utility>
#include "../fn/unroll.hpp"
#include "../meta/splicetup.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<std::size_t arity, std::size_t prev_idx = 0, typename F, typename... Args>
	[[nodiscard]] constexpr decltype(auto) distrargsrecurs(F&& fn, Args&&... args) noexcept(false) {
		static_assert(prev_idx < arity, "index of previous result must be within functor arity");
		static_assert((arity > 1) || !sizeof...(Args), "arguments must be distributable across functor calls");
		static_assert(sizeof...(Args) >= arity, "number of arguments must not be less than functor arity");
		if constexpr (sizeof...(Args) == arity) {
			return std::invoke(X4FWD(fn), X4FWD(args)...);
		} else {
			const auto args_tuple = std::forward_as_tuple(X4FWD(args)...);
			const auto result = x4::splicetup<(prev_idx + arity)>(args_tuple, std::forward_as_tuple(std::apply(fn, x4::splicetup<arity, (sizeof...(Args) - arity)>(args_tuple))));
			return x4::unroll<(sizeof...(Args) - arity + 1)>([&fn, &result]<std::size_t... i> -> decltype(auto) {
				return x4::distrargsrecurs<arity, prev_idx>(X4FWD(fn), std::get<(i + arity)>(std::move(result))...);
			});
		}
	}
}
