#ifndef DETAIL_XIEITE_HEADER_FN_RANGE_CMP
#	define DETAIL_XIEITE_HEADER_FN_RANGE_CMP
#
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <utility>
#	include "../fn/synth_three_way.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_noex_iter.hpp"
#	include "../trait/is_noex_sentinel.hpp"
#	include "../trait/is_order.hpp"

namespace xieite {
	template<std::input_iterator Iter1, std::sentinel_for<Iter1> Sentinel1, std::input_iterator Iter2, std::sentinel_for<Iter2> Sentinel2>
	[[nodiscard]] constexpr auto range_cmp(Iter1 begin0, Sentinel1 end0, Iter2 begin1, Sentinel2 end1, auto cmp = xieite::synth_three_way, auto proj = std::identity())
	noexcept(xieite::is_noex_iter<Iter1> && xieite::is_noex_sentinel<Sentinel1, Iter1> && xieite::is_noex_iter<Iter2> && xieite::is_noex_sentinel<Sentinel2, Iter2> && noexcept(cmp(proj(*begin0), proj(*begin1))))
	requires(xieite::is_order<decltype(cmp(proj(*begin0), proj(*begin1)))>) {
		bool exhaust0 = (begin0 == end0);
		bool exhaust1 = (begin1 == end1);
		for (; !exhaust0 && !exhaust1; exhaust0 = (++begin0 == end0), exhaust1 = (++begin1 == end1)) {
			if (auto result = cmp(proj(*begin0), proj(*begin1)); !std::is_eq(result)) {
				return result;
			}
		}
		return exhaust0 <=> exhaust1;
	}

	template<std::ranges::input_range Range, std::input_iterator Iter>
	[[nodiscard]] constexpr auto range_cmp(Range&& lhs, Iter begin, std::sentinel_for<Iter> auto end, auto cmp = xieite::synth_three_way, auto proj = std::identity())
		XIEITE_ARROW(xieite::range_cmp(std::ranges::begin(lhs), std::ranges::end(lhs), begin, end, std::move(cmp), std::move(proj)))

	template<std::input_iterator Iter>
	[[nodiscard]] constexpr auto range_cmp(Iter begin, std::sentinel_for<Iter> auto end, std::ranges::input_range auto&& rhs, auto cmp = xieite::synth_three_way, auto proj = std::identity())
		XIEITE_ARROW(xieite::range_cmp(begin, end, std::ranges::begin(rhs), std::ranges::end(rhs), std::move(cmp), std::move(proj)))

	[[nodiscard]] constexpr auto range_cmp(std::ranges::input_range auto&& lhs, std::ranges::input_range auto&& rhs, auto cmp = xieite::synth_three_way, auto proj = std::identity())
		XIEITE_ARROW(xieite::range_cmp(std::ranges::begin(lhs), std::ranges::end(lhs), std::ranges::begin(rhs), std::ranges::end(rhs), std::move(cmp), std::move(proj)))
}

#endif

// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare_three_way.html#Possible_implementation
