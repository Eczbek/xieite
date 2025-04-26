#ifndef DETAIL_XIEITE_HEADER_FN_MEMOIZE
#	define DETAIL_XIEITE_HEADER_FN_MEMOIZE
#
#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <tuple>
#	include <type_traits>
#	include <unordered_map>
#	include <utility>
#	include "../fn/unroll.hpp"
#	include "../math/hash_combine.hpp"
#	include "../trait/is_hashable.hpp"

namespace DETAIL_XIEITE::memoize {
	template<typename Fn, typename... Args>
	requires(std::invocable<Fn, Args...>)
	struct memo {
		Fn fn;
		std::tuple<Args...> args;

		[[nodiscard]] constexpr memo(const Fn& fn, const std::tuple<Args...>& args) noexcept
		: fn(fn), args(args) {}

		template<typename... OtherArgs>
		[[nodiscard]] friend constexpr bool operator==(const DETAIL_XIEITE::memoize::memo<Fn, Args...>& lhs, const DETAIL_XIEITE::memoize::memo<Fn, OtherArgs...>& rhs) noexcept {
			return (lhs.fn == rhs.fn) && (lhs.args == rhs.args);
		}
	};

	struct hash {
		using is_transparent = void;

		template<typename Fn, typename... Args>
		[[nodiscard]] static std::size_t operator()(const DETAIL_XIEITE::memoize::memo<Fn, Args...>& memo) noexcept(false) {
			return xieite::unroll<Args...>([&memo]<std::size_t... i> -> std::size_t {
				return xieite::hash_combine(
					([&memo] -> std::size_t {
						if constexpr (xieite::is_hashable<Fn>) {
							return std::hash<Fn>()(memo.fn);
						} else {
							return memo, throw, 0;
						}
					})(),
					std::hash<std::decay_t<Args...[i]>>()(std::get<i>(memo.args))...
				);
			});
		}
	};
}

namespace xieite {
	template<typename Fn, typename... Args>
	requires(std::invocable<Fn, Args...>)
	std::invoke_result_t<Fn, Args...> memoize(Fn fn, const Args&... args)
	noexcept(std::is_nothrow_invocable_v<Fn, Args...>) {
		if constexpr (
			!std::same_as<std::invoke_result_t<Fn, Args...>, void>
			&& (xieite::is_hashable<Fn> || std::is_empty_v<Fn>)
			&& std::equality_comparable<Fn>
			&& (... && xieite::is_hashable<Args>)
		) {
			static std::unordered_map<DETAIL_XIEITE::memoize::memo<Fn, std::decay_t<Args>...>, std::invoke_result_t<Fn&, Args...>, DETAIL_XIEITE::memoize::hash, std::equal_to<>> map;
			if (const auto iter = map.find(DETAIL_XIEITE::memoize::memo<Fn, const Args&...>(fn, std::tie(args...))); iter != map.end()) {
				return iter->second;
			} else {
				const auto tuple = std::make_tuple(args...);
				std::invoke_result_t<Fn, Args...> result = std::invoke(fn, args...);
				map.emplace(std::piecewise_construct, std::forward_as_tuple(std::move(fn), std::move(tuple)), std::forward_as_tuple(result));
				return result;
			}
		} else {
			return std::invoke(fn, args...);
		}
	}
}

#endif

// Thanks to wreien (https://github.com/wreien) for rewriting everything entirely
