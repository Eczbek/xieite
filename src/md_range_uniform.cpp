module;

#include <xieite/lift.hpp>

export module xieite:md_range_uniform;

import std;
import :is_nothrow_range;

export namespace xieite {
	template<std::ranges::input_range R>
	requires(std::ranges::input_range<std::ranges::range_value_t<R>>)
	[[nodiscard]] constexpr bool md_range_uniform(R&& range)
	noexcept(([]<typename S>(this auto self) {
		if constexpr (!std::ranges::input_range<S>) {
			return true;
		} else if constexpr (!xieite::is_nothrow_range<S>) {
			return false;
		} else {
			return self.template operator()<std::ranges::range_value_t<R>>();
		}
	}).template operator()<R>()) {
		if constexpr (std::ranges::input_range<std::ranges::range_value_t<std::ranges::range_value_t<R>>>) {
			return std::ranges::all_of(range, XIEITE_LIFT(xieite::md_range_uniform));
		} else {
			return std::ranges::all_of(
				range,
				[first = std::ranges::size(*std::ranges::begin(range))](std::ranges::range_common_reference_t<R> item) {
					return std::ranges::size(item) == first;
				}
			);
		}
	}
}
