#ifndef XIEITE_HEADER_CONTAINERS_REVERSE_TUPLE
#	define XIEITE_HEADER_CONTAINERS_REVERSE_TUPLE

#	include <cstddef>
#	include <tuple>
#	include <utility>
#	include "../concepts/no_throw_convertible_to.hpp"
#	include "../types/list.hpp"

namespace xieite::containers {
	template<typename... Types_>
	[[nodiscard]] constexpr typename xieite::types::List<Types_...>::Reverse::Apply<std::tuple> reverseTuple(const std::tuple<Types_...>& tuple)
	noexcept(([]<std::size_t... i_>(std::index_sequence<i_...>) {
		return (... && xieite::concepts::NoThrowConvertibleTo<typename xieite::types::List<Types_...>::At<i_>, typename xieite::types::List<Types_...>::Reverse::At<i_>>);
	})(std::make_index_sequence<sizeof...(Types_)>())) {
		using Reversed = xieite::types::List<Types_...>::Reverse;
		return ([&tuple]<std::size_t... i_>(std::index_sequence<i_...>) {
			return typename Reversed::Apply<std::tuple>(static_cast<typename Reversed::At<i_>>(std::get<sizeof...(Types_) - i_ - 1>(tuple))...);
		})(std::make_index_sequence<sizeof...(Types_)>());
	}
}

#endif

// Thanks to fux for helping make this
