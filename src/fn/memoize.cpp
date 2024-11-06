module;

#include <xieite/fn.hpp>

export module xieite:memoize;

import std;
import :cond;
import :hash_combine;
import :is_hashable;
import :unroll;

template<typename F, typename... Args>
requires(std::invocable<F, Args...>)
struct memo {
	F fn;
	std::tuple<Args...> args;

	constexpr memo(const F& fn, const std::tuple<Args...>& args) noexcept
	: fn(fn), args(args) {}

	[[nodiscard]] friend bool operator==(const memo<F, Args...>&, const memo<F, Args...>&) = default;

	template<typename... OtherArgs>
	[[nodiscard]] friend bool operator==(const memo<F, Args...>& left, const memo<F, OtherArgs...>& right) noexcept {
		return (left.fn == right.fn) && (left.args == right.args);
	}
};

struct memo_hash {
	using is_transparent = void;

	template<typename F, typename... Args>
	[[nodiscard]] static std::size_t operator()(const memo<F, Args...>& memo) noexcept(false) {
		return xieite::unroll<Args...>([&memo]<std::size_t... i> -> std::size_t {
			return xieite::hash_combine(
				xieite::cond<xieite::is_hashable<F>>(std::hash<F>(), XIEITE_FN(0))(memo.fn),
				std::hash<std::decay_t<std::tuple_element_t<i, std::tuple<Args...>>>>()(std::get<i>(memo.args))...
			);
		});
	}
};

export namespace xieite {
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
			static std::unordered_map<memo<F, std::decay_t<Args>...>, std::invoke_result_t<F&, Args...>, memo_hash, std::ranges::equal_to> map;
			const auto iterator = map.find(memo<F, const Args&...>(fn, std::tie(args...)));
			if (iterator != map.end()) {
				return iterator->second;
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
