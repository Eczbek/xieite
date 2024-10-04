module;

#include <xieite/forward.hpp>

export module xieite:containers.applyArray;

import std;
import :types.List;

export namespace xieite::containers {
	template<typename Functor, typename Value, std::size_t size, std::convertible_to<std::array<Value, size>> Array>
	requires(xieite::types::List<Value>::template Repeat<size>::template Prepend<Functor>::template To<std::is_invocable>::value)
	constexpr typename xieite::types::List<Value>::template Repeat<size>::template Prepend<Functor>::template To<std::invoke_result_t> applyArray(Functor&& functor, Array&& array)
	noexcept(xieite::types::List<Value>::template Repeat<size>::template Prepend<Functor>::template To<std::is_nothrow_invocable>::value) {
		return ([&functor, &array]<std::size_t... i>(std::index_sequence<i...>) {
			std::invoke(XIEITE_FORWARD(functor), std::forward_like<Array>(array[i])...);
		})(std::make_index_sequence<size>());
	}

	template<typename Structure, typename Value, std::size_t size, std::convertible_to<std::array<Value, size>> Array>
	requires(xieite::types::List<Value>::template Repeat<size>::template Prepend<Structure>::template To<std::is_constructible>::value)
	[[nodiscard]] constexpr Structure applyArray(Array&& array)
	noexcept(xieite::types::List<Value>::template Repeat<size>::template Prepend<Structure>::template To<std::is_nothrow_constructible>::value) {
		return ([&array]<std::size_t... i>(std::index_sequence<i...>) {
			return Structure(std::forward_like<Array>(array[i])...);
		})(std::make_index_sequence<size>());
	}
}
