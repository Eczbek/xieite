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
	template<typename Functor_, typename... Argument_>
	requires(std::invocable<Functor_, Argument_...>)
	struct Memo {
		Functor_ functor;
		std::tuple<Argument_...> arguments;

		constexpr Memo(const Functor_& functor, const std::tuple<Argument_...>& arguments) noexcept
		: functor(functor), arguments(arguments) {}

		bool operator==(const xieite::detail::Memo<Functor_, Argument_...>&) const noexcept = default;

		template<typename... OtherArguments>
		bool operator==(const xieite::detail::Memo<Functor_, OtherArguments...>& memo) const noexcept {
			return (this->functor == memo.functor) && (this->arguments == memo.arguments);
		}
	};

	struct MemoHash {
		using is_transparent = void;

		template<typename Functor_, typename... Argument_>
		static std::size_t operator()(const xieite::detail::Memo<Functor_, Argument_...>& memo) {
			return ([&memo]<std::size_t... i_>(std::index_sequence<i_...>) {
				return xieite::hashes::combine(([&memo] {
					if constexpr (xieite::concepts::Hashable<Functor_>) {
						return std::hash<Functor_>()(memo.functor);
					} else {
						return 0;
					}
				})(), std::hash<std::decay_t<std::tuple_element_t<i_, std::tuple<Argument_...>>>>()(std::get<i_>(memo.arguments))...);
			})(std::make_index_sequence<sizeof...(Argument_)>());
		}
	};
}

namespace xieite::functors {
	template<typename... Argument_, std::invocable<Argument_...> Functor_>
	std::invoke_result_t<Functor_, Argument_...> memoize(Functor_ functor, const Argument_&... arguments)
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, Argument_...>) {
		if constexpr (!std::same_as<std::invoke_result_t<Functor_, Argument_...>, void> && (xieite::concepts::Hashable<Functor_> || std::is_empty_v<Functor_>) && std::equality_comparable<Functor_> && (... && xieite::concepts::Hashable<Argument_>)) {
			static std::unordered_map<xieite::detail::Memo<Functor_, std::decay_t<Argument_>...>, std::invoke_result_t<Functor_&, Argument_...>, xieite::detail::MemoHash, std::equal_to<>> map;
			const auto iterator = map.find(xieite::detail::Memo<Functor_, const Argument_&...>(functor, std::tie(arguments...)));
			if (iterator != map.end()) {
				return iterator->second;
			} else {
				const auto tuple = std::make_tuple(arguments...);
				std::invoke_result_t<Functor_, Argument_...> result = std::invoke(functor, arguments...);
				map.emplace(std::piecewise_construct, std::forward_as_tuple(std::move(functor), std::move(tuple)), std::forward_as_tuple(result));
				return result;
			}
		} else {
			return std::invoke(functor, arguments...);
		}
	}
}

#endif

// Thanks to hspk and fux for fixing my original code, and wreien (https://github.com/wreien) for rewriting everything entirely
