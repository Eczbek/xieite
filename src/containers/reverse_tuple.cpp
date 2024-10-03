module;

#include <xieite/sequence.hpp>

export module xieite:containers.reverseTuple;

import std;
import :concepts.NoThrowConvertibleTo;
import :types.List;

export namespace xieite::containers {
	template<typename... Types>
	[[nodiscard]] constexpr typename xieite::types::List<Types...>::Reverse::template To<std::tuple> reverseTuple(const std::tuple<Types...>& tuple) noexcept {
		return XIEITE_SEQUENCE(i, sizeof...(Types), xieite::types::List<Types...>::Reverse::template To<std::tuple>(std::get<sizeof...(Types) - i - 1>(tuple)...));
	}
}
