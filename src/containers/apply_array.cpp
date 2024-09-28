module;

#include <xieite/forward.hpp>
#include <xieite/sequence.hpp>

export module xieite:containers.applyArray;

import std;
import :types.List;

export namespace xieite::containers {
	template<typename Functor, typename Value, std::size_t size, std::convertible_to<std::array<Value, size>> Array>
	requires(xieite::types::List<Value>::template Repeat<size>::template Prepend<Functor>::template ApplyRange<std::is_invocable>::value)
	constexpr decltype(auto) applyArray(Functor&& functor, Array&& array)
	noexcept(xieite::types::List<Value>::template Repeat<size>::template Prepend<Functor>::template ApplyRange<std::is_nothrow_invocable>::value) {
		return XIEITE_SEQUENCE(i, size, std::invoke(XIEITE_FORWARD(functor), std::forward_like<Array>(array[i])...));
	}

	template<typename Structure, typename Value, std::size_t size, std::convertible_to<std::array<Value, size>> Array>
	requires(xieite::types::List<Value>::template Repeat<size>::template Prepend<Structure>::template ApplyRange<std::is_constructible>::value)
	[[nodiscard]] constexpr Structure applyArray(Array&& array)
	noexcept(xieite::types::List<Value>::template Repeat<size>::template Prepend<Structure>::template ApplyRange<std::is_nothrow_constructible>::value) {
		return XIEITE_SEQUENCE(i, size, Structure(std::forward_like<Array>(array[i])...));
	}
}
