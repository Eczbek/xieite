module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>
#include <xieite/lift.hpp>

export module xieite:containers.makeArray;

import std;
import :concepts.Invocable;
import :functors.unroll;

export namespace xieite::containers {
	template<typename Value, std::size_t size, std::ranges::input_range Range, xieite::concepts::Invocable<Value(std::ranges::range_common_reference_t<Range>)> Functor = decltype(XIEITE_LIFT_PREFIX_CAPTURE(, static_cast<Value>))>
	[[nodiscard]] constexpr std::array<Value, size> makeArray(Range&& range, Functor&& converter = Functor())
	XIEITE_ARROW_BASE(xieite::functors::unroll<size>([&range, &converter]<std::size_t... i> {
		auto iterator = std::ranges::begin(XIEITE_FORWARD(range));
		return std::array<Value, size> {
			([&converter, &iterator] -> decltype(auto) {
				if constexpr (!!i) {
					++iterator;
				}
				return std::invoke(converter, *iterator);
			})()...
		};
	}))
}
