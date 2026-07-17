#ifndef DETAIL_XTE_HEADER_UTIL_SYNTH_THREE_WAY
#	define DETAIL_XTE_HEADER_UTIL_SYNTH_THREE_WAY
#
#	include "../math/less.hpp"
#	include "../meta/fake.hpp"
#	include "../preproc/returns.hpp"
#	include <compare>

namespace xte {
	inline constexpr auto synth_three_way = [](const auto& lhs, const auto& rhs) static XTE_RETURNS_CHOOSE(
		(std::three_way_comparable_with<decltype(lhs), decltype(rhs)>),
		lhs <=> rhs,
		xte::less(lhs, rhs)
			? std::weak_ordering::less
			: xte::less(rhs, lhs)
				? std::weak_ordering::greater
				: std::weak_ordering::equivalent
	);

	template<typename T, typename U = T>
	using synth_three_way_result = decltype(xte::synth_three_way(xte::fake<T&>(), xte::fake<U&>()));
}

#endif

// https://en.cppreference.com/w/cpp/standard_library/synth-three-way
