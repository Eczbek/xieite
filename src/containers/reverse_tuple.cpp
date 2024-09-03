export module xieite:containers.reverseTuple;

import std;
import :concepts.NoThrowConvertibleTo;

template<typename... Arguments>
using ReverseTupleHelper = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
	return std::declval<std::tuple<std::tuple_element_t<sizeof...(Arguments) - i - 1, std::tuple<Arguments...>>...>>();
})(std::index_sequence_for<Arguments...>()));

export namespace xieite::containers {
	template<typename... Types>
	[[nodiscard]] constexpr ReverseTupleHelper<Types...> reverseTuple(const std::tuple<Types...>& tuple) noexcept {
		return ([&tuple]<std::size_t... i>(std::index_sequence<i...>) -> ReverseTupleHelper<Types...> {
			return ReverseTupleHelper<Types...>(std::get<sizeof...(Types) - i - 1>(tuple)...);
		})(std::make_index_sequence<sizeof...(Types)>());
	}
}

// TODO: Replace helper with `xieite::types::List`
