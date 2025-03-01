#pragma once

#include <cstddef>
#include <functional>
#include <tuple>
#include <utility>
#include "../fn/unroll.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<std::size_t arity, typename F, typename... Args>
	constexpr void distrargs(F&& fn, Args&&... args) noexcept(false) {
		static_assert(!!arity || !sizeof...(Args), "arguments must be distributable across functor calls");
		static_assert(sizeof...(Args) >= arity, "number of arguments must not be less than functor arity");
		if constexpr (sizeof...(Args) == arity) {
			std::invoke(X4FWD(fn), X4FWD(args)...);
		} else {
			const auto args_tuple = std::forward_as_tuple(X4FWD(args)...);
			x4::unroll<arity>([&fn, &args_tuple]<std::size_t... i> -> void {
				std::invoke(fn, std::get<i>(std::move(args_tuple))...);
			});
			x4::unroll<sizeof...(Args) - arity>([&fn, &args_tuple]<std::size_t... i> -> void {
				x4::distrargs<arity>(X4FWD(fn), std::get<(i + arity)>(std::move(args_tuple))...);
			});
		}
	}
}
