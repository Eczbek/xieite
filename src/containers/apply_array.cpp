module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:containers.applyArray;

import std;
import :functors.unroll;

export namespace xieite::containers {
	template<typename Functor, typename Value, std::size_t size, std::convertible_to<std::array<Value, size>> Array>
	constexpr auto applyArray(Functor&& functor, Array&& array)
	XIEITE_ARROW(xieite::functors::unroll<size>([&functor, &array]<std::size_t... i> {
		return std::invoke(XIEITE_FORWARD(functor), std::forward_like<Array>(array[i])...);
	}))

	template<typename Structure, typename Value, std::size_t size, std::convertible_to<std::array<Value, size>> Array>
	[[nodiscard]] constexpr Structure applyArray(Array&& array)
	XIEITE_ARROW_BASE(xieite::functors::unroll<size>([&array]<std::size_t... i> {
		return Structure(std::forward_like<Array>(array[i])...);
	}))
}
