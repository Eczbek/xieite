module;

#include <xieite/lift.hpp>

export module xieite:containers.makeArray;

import std;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;
import :concepts.NoThrowOperableRange;

export namespace xieite::containers {
	template<typename Value, std::size_t size, std::ranges::input_range Range, xieite::concepts::Invocable<Value(std::ranges::range_common_reference_t<Range>)> Functor = decltype(XIEITE_LIFT_PREFIX(static_cast<Value>))>
	requires(std::convertible_to<std::ranges::range_value_t<Range>, Value>)
	[[nodiscard]] constexpr std::array<Value, size> makeArray(Range&& range, Functor&& converter = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Value(std::ranges::range_common_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>) {
		return ([&range, &converter]<std::size_t... i>(std::index_sequence<i...>) {
			auto iterator = std::ranges::begin(range);
			return std::array<Value, size> {
				([&converter, &iterator] -> decltype(auto) {
					if constexpr (!!i) {
						++iterator;
					}
					return std::invoke(converter, *iterator);
				})()...
			};
		})(std::make_index_sequence<size>());
	}
}
