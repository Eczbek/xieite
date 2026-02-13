#ifndef DETAIL_XTE_HEADER_FUNC_SYNTH_THREE_WAY
#	define DETAIL_XTE_HEADER_FUNC_SYNTH_THREE_WAY
#
#	include "../trait/is_bool_testable.hpp"
#	include "../trait/is_noex_bool_testable.hpp"
#	include <compare>
#	include <utility>

namespace xte {
	inline constexpr auto synth_three_way =
		[]<typename T, typename U>(const T& lhs, const U& rhs) static noexcept(requires {
			{ lhs < rhs } -> xte::is_noex_bool_testable;
			{ rhs < lhs } -> xte::is_noex_bool_testable;
		}) -> decltype(auto) requires(requires {
			{ lhs < rhs } -> xte::is_bool_testable;
			{ rhs < lhs } -> xte::is_bool_testable;
		}) {
			if constexpr (std::three_way_comparable_with<T, U>) {
				return lhs <=> rhs;
			} else {
				return (lhs < rhs)
					? std::weak_ordering::less
					: (rhs < lhs)
						? std::weak_ordering::greater
						: std::weak_ordering::equivalent;
			}
		};

	template<typename T, typename U = T>
	using synth_three_way_result = decltype(xte::synth_three_way(std::declval<T&>(), std::declval<U&>()));
}

#endif

// https://en.cppreference.com/w/cpp/standard_library/synth-three-way
