export module xieite:containers.reverseTuple;

import std;
import :concepts.NoThrowConvertibleTo;
import :types.List;

export namespace xieite::containers {
	template<typename... Types>
	[[nodiscard]] constexpr xieite::types::List<Types...>::Reverse::template ApplyRange<std::tuple> reverseTuple(const std::tuple<Types...>& tuple) noexcept {
		return ([&tuple]<std::size_t... i>(std::index_sequence<i...>) {
			return xieite::types::List<Types...>::Reverse::template ApplyRange<std::tuple>(std::get<sizeof...(Types) - i - 1>(tuple)...);
		})(std::make_index_sequence<sizeof...(Types)>());
	}
}
