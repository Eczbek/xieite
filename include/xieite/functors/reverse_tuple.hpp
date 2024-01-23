#ifndef XIEITE_HEADER_FUNCTORS_REVERSE_TUPLE
#	define XIEITE_HEADER_FUNCTORS_REVERSE_TUPLE

#	include <cstddef>
#	include <tuple>
#	include <utility>
#	include "../concepts/no_throw_convertible_to.hpp"
#	include "../types/list.hpp"

namespace xieite::functors {
	template<typename... Types>
	[[nodiscard]] constexpr typename xieite::types::List<Types...>::Reverse::Apply<std::tuple> reverseTuple(const std::tuple<Types...>& tuple)
	noexcept(([]<std::size_t... indices>(std::index_sequence<indices...>) -> bool {
		return (... && xieite::concepts::NoThrowConvertibleTo<typename xieite::types::List<Types...>::At<indices>, typename xieite::types::List<Types...>::Reverse::At<indices>>);
	})(std::make_index_sequence<sizeof...(Types)>())) {
		using Reversed = xieite::types::List<Types...>::Reverse;
		return ([&tuple]<std::size_t... indices>(std::index_sequence<indices...>) -> typename Reversed::Apply<std::tuple> {
			return typename Reversed::Apply<std::tuple>(static_cast<typename Reversed::At<indices>>(std::get<sizeof...(Types) - indices - 1>(tuple))...);
		})(std::make_index_sequence<sizeof...(Types)>());
	}
}

#endif

// Thanks to fux for help with making this
