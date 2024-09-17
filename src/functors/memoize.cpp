export module xieite:functors.memoize;

import std;
import :concepts.Hashable;
import :hashes.combine;

namespace {
	template<typename Functor, typename... Arguments>
	requires(std::invocable<Functor, Arguments...>)
	struct Memo {
		Functor functor;
		std::tuple<Arguments...> arguments;

		constexpr Memo(const Functor& functor, const std::tuple<Arguments...>& arguments) noexcept
		: functor(functor), arguments(arguments) {}

		bool operator==(const Memo<Functor, Arguments...>&) const noexcept = default;

		template<typename... OtherArguments>
		bool operator==(const Memo<Functor, OtherArguments...>& memo) const noexcept {
			return (this->functor == memo.functor) && (this->arguments == memo.arguments);
		}
	};

	struct MemoHash {
		using is_transparent = void; // For use in `std::unordered_map`

		template<typename Functor, typename... Arguments>
		static std::size_t operator()(const Memo<Functor, Arguments...>& memo) noexcept(false) {
			return ([&memo]<std::size_t... i>(std::index_sequence<i...>) {
				return xieite::hashes::combine(([&memo] {
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

export namespace xieite::functors {
	template<typename... Arguments, std::invocable<Arguments...> Functor>
	std::invoke_result_t<Functor, Arguments...> memoize(Functor functor, const Arguments&... arguments)
	noexcept(std::is_nothrow_invocable_v<Functor, Arguments...>) {
		if constexpr (!std::same_as<std::invoke_result_t<Functor, Arguments...>, void> && (xieite::concepts::Hashable<Functor> || std::is_empty_v<Functor>) && std::equality_comparable<Functor> && (... && xieite::concepts::Hashable<Arguments>)) {
			static std::unordered_map<Memo<Functor, std::decay_t<Arguments>...>, std::invoke_result_t<Functor&, Arguments...>, MemoHash, std::ranges::equal_to> map;
			const auto iterator = map.find(Memo<Functor, const Arguments&...>(functor, std::tie(arguments...)));
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

// Thanks to wreien (https://github.com/wreien) for rewriting everything entirely
