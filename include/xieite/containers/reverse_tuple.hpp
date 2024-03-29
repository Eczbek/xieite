#ifndef XIEITE_HEADER_CONTAINERS_REVERSE_TUPLE
#	define XIEITE_HEADER_CONTAINERS_REVERSE_TUPLE

#	include <cstddef>
#	include <tuple>
#	include <utility>
#	include "../concepts/no_throw_convertible_to.hpp"
#	include "../types/list.hpp"

namespace xieite::containers {
	template<typename... Types>
	[[nodiscard]] constexpr typename xieite::types::List<Types...>::Reverse::Apply<std::tuple> reverseTuple(const std::tuple<Types...>& tuple)
	noexcept(([]<std::size_t... i>(std::index_sequence<i...>) -> bool {
		return (... && xieite::concepts::NoThrowConvertibleTo<typename xieite::types::List<Types...>::At<i>, typename xieite::types::List<Types...>::Reverse::At<i>>);
	})(std::make_index_sequence<sizeof...(Types)>())) {
		using Reversed = xieite::types::List<Types...>::Reverse;
		return ([&tuple]<std::size_t... i>(std::index_sequence<i...>) -> typename Reversed::Apply<std::tuple> {
			return typename Reversed::Apply<std::tuple>(static_cast<typename Reversed::At<i>>(std::get<sizeof...(Types) - i - 1>(tuple))...);
		})(std::make_index_sequence<sizeof...(Types)>());
	}
}

#endif

// Thanks to fux for helping make this
