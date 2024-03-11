#ifndef XIEITE_HEADER_FUNCTORS_MEMOIZE
#	define XIEITE_HEADER_FUNCTORS_MEMOIZE

#	include <concepts>
#	include <cstddef>
#	include <functional>
#	include <tuple>
#	include <type_traits>
#	include <unordered_map>
#	include <utility>
#	include "../concepts/hashable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../hashes/combine.hpp"

namespace xieite::detail {
	template<typename Functor, typename... Arguments>
	requires(std::invocable<Functor, Arguments...>)
	struct Memo {
		Functor functor;
		std::tuple<Arguments...> arguments;

		constexpr Memo(const Functor& functor, const std::tuple<Arguments...>& arguments) noexcept
		: functor(functor), arguments(arguments) {}

		bool operator==(const xieite::detail::Memo<Functor, Arguments...>&) const noexcept = default;

		template<typename... OtherArguments>
		bool operator==(const xieite::detail::Memo<Functor, OtherArguments...>& memo) const noexcept {
			return (this->functor == memo.functor) && (this->arguments == memo.arguments);
		}
	};

	struct MemoHash {
		using is_transparent = void;

		template<typename Functor, typename... Arguments>
		static std::size_t operator()(const xieite::detail::Memo<Functor, Arguments...>& memo) {
			return ([&memo]<std::size_t... i>(std::index_sequence<i...>) -> std::size_t {
				return xieite::hashes::combine(([&memo] -> std::size_t {
					if constexpr (xieite::concepts::Hashable<Functor>) {
						return std::hash<Functor>()(memo.functor);
					} else {
						return 0;
					}
				})(), std::hash<std::decay_t<std::tuple_element_t<i, std::tuple<Arguments...>>>>()(std::get<i>(memo.arguments))...);
			})(std::make_index_sequence<sizeof...(Arguments)>());
		}
	};
}

namespace xieite::functors {
	template<typename... Arguments, std::invocable<Arguments...> Functor>
	std::invoke_result_t<Functor, Arguments...> memoize(Functor functor, const Arguments&... arguments)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Arguments...>) {
		if constexpr (!std::same_as<std::invoke_result_t<Functor, Arguments...>, void> && (xieite::concepts::Hashable<Functor> || std::is_empty_v<Functor>) && std::equality_comparable<Functor> && (... && xieite::concepts::Hashable<Arguments>)) {
			static std::unordered_map<xieite::detail::Memo<Functor, std::decay_t<Arguments>...>, std::invoke_result_t<Functor&, Arguments...>, xieite::detail::MemoHash, std::equal_to<>> map;
			const auto iterator = map.find(xieite::detail::Memo<Functor, const Arguments&...>(functor, std::tie(arguments...)));
			if (iterator != map.end()) {
				return iterator->second;
			} else {
				const auto tuple = std::make_tuple(arguments...);
				std::invoke_result_t<Functor, Arguments...> result = std::invoke(functor, arguments...);
				map.emplace(std::piecewise_construct, std::forward_as_tuple(std::move(functor), std::move(tuple)), std::forward_as_tuple(result));
				return result;
			}
		} else {
			return std::invoke(functor, arguments...);
		}
	}
}

#endif

// Thanks to hspk. and fux for fixing my original code, and wreien (https://github.com/wreien) for rewriting everything entirely
