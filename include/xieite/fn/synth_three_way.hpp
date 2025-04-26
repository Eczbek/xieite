#ifndef DETAIL_XIEITE_HEADER_FN_SYNTH_THREE_WAY
#	define DETAIL_XIEITE_HEADER_FN_SYNTH_THREE_WAY
#
#	include <compare>
#	include <utility>
#	include "../trait/is_bool_testable.hpp"
#	include "../trait/is_noex_bool_testable.hpp"

namespace xieite {
	inline constexpr auto synth_three_way = []<typename T, typename U>(const T& lhs, const U& rhs)
		noexcept(requires {
			{ lhs < rhs } -> xieite::is_noex_bool_testable;
			{ rhs < lhs } -> xieite::is_noex_bool_testable;
		})
		-> decltype(auto)
		requires(requires {
			{ lhs < rhs } -> xieite::is_bool_testable;
			{ rhs < lhs } -> xieite::is_bool_testable;
		}) {
			if constexpr (std::three_way_comparable_with<T, U>) {
				return lhs <=> rhs;
			} else {
				if (lhs < rhs) {
					return std::weak_ordering::less;
				}
				if (rhs < lhs) {
					return std::weak_ordering::greater;
				}
				return std::weak_ordering::equivalent;
			}
		};

	template<typename T, typename U = T>
	using synth_three_way_result = decltype(xieite::synth_three_way(std::declval<T&>(), std::declval<U&>()));
}

#endif

// https://en.cppreference.com/w/cpp/standard_library/synth-three-way
