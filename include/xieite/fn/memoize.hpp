#pragma once

#include <concepts>
#include <cstddef>
#include <functional>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include "../fn/unroll.hpp"
#include "../math/hash_combine.hpp"
#include "../trait/is_hashable.hpp"

namespace XIEITE_DETAIL::memoize {
	template<typename F, typename... Args>
	requires(std::invocable<F, Args...>)
	struct memo {
		F fn;
		std::tuple<Args...> args;

		[[nodiscard]] constexpr memo(const F& fn, const std::tuple<Args...>& args) noexcept
		: fn(fn), args(args) {}

		template<typename... OtherArgs>
		[[nodiscard]] friend constexpr bool operator==(const XIEITE_DETAIL::memoize::memo<F, Args...>& l, const XIEITE_DETAIL::memoize::memo<F, OtherArgs...>& r) noexcept {
			return (l.fn == r.fn) && (l.args == r.args);
		}
	};

	struct hash {
		using is_transparent = void;

		template<typename F, typename... Args>
		[[nodiscard]] static std::size_t operator()(const XIEITE_DETAIL::memoize::memo<F, Args...>& memo) noexcept(false) {
			return xieite::unroll<Args...>([&memo]<std::size_t... i> -> std::size_t {
				return xieite::hash_combine(
					([&memo] -> std::size_t {
						if constexpr (xieite::is_hashable<F>) {
							return std::hash<F>()(memo.fn);
						} else {
							return void(memo), 0;
						}
					})(),
					std::hash<std::decay_t<Args...[i]>>()(std::get<i>(memo.args))...
				);
			});
		}
	};
}

namespace xieite {
	template<typename F, typename... Args>
	requires(std::invocable<F, Args...>)
	std::invoke_result_t<F, Args...> memoize(F fn, const Args&... args)
	noexcept(std::is_nothrow_invocable_v<F, Args...>) {
		if constexpr (
			!std::same_as<std::invoke_result_t<F, Args...>, void>
			&& (xieite::is_hashable<F> || std::is_empty_v<F>)
			&& std::equality_comparable<F>
			&& (... && xieite::is_hashable<Args>)
		) {
			static std::unordered_map<XIEITE_DETAIL::memoize::memo<F, std::decay_t<Args>...>, std::invoke_result_t<F&, Args...>, XIEITE_DETAIL::memoize::hash, std::equal_to<>> map;
			if (const auto iter = map.find(XIEITE_DETAIL::memoize::memo<F, const Args&...>(fn, std::tie(args...))); iter != map.end()) {
				return iter->second;
			} else {
				const auto tuple = std::make_tuple(args...);
				std::invoke_result_t<F, Args...> result = std::invoke(fn, args...);
				map.emplace(std::piecewise_construct, std::forward_as_tuple(std::move(fn), std::move(tuple)), std::forward_as_tuple(result));
				return result;
			}
		} else {
			return std::invoke(fn, args...);
		}
	}
}

// Thanks to wreien (https://github.com/wreien) for rewriting everything entirely
