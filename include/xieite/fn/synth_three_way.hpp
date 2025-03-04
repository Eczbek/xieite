#pragma once

#include <compare>
#include <utility>
#include "../trait/is_bool_testable.hpp"
#include "../trait/is_noex_bool_testable.hpp"

namespace xieite {
	inline constexpr auto synth_three_way =
		[]<typename T, typename U>(const T& l, const U& r)
		noexcept(requires {
			{ l < r } -> xieite::is_noex_bool_testable;
			{ r < l } -> xieite::is_noex_bool_testable;
		})
		-> decltype(auto)
		requires(requires {
			{ l < r } -> xieite::is_bool_testable;
			{ r < l } -> xieite::is_bool_testable;
		}) {
			if constexpr (std::three_way_comparable_with<T, U>) {
				return l <=> r;
			} else {
				if (l < r) {
					return std::weak_ordering::less;
				}
				if (r < l) {
					return std::weak_ordering::greater;
				}
				return std::weak_ordering::equivalent;
			}
		};

	template<typename T, typename U = T>
	using synth_three_way_result = decltype(xieite::synth_three_way(std::declval<T&>(), std::declval<U&>()));
}

// https://en.cppreference.com/w/cpp/standard_library/synth-three-way
