#ifndef DETAIL_XTE_HEADER_DATA_RANGE_CMP
#	define DETAIL_XTE_HEADER_DATA_RANGE_CMP
#
#	include "../func/nop.hpp"
#	include "../func/synth_three_way.hpp"
#	include "../func/visitor.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_noex_iter.hpp"
#	include "../trait/is_noex_sentinel.hpp"
#	include "../trait/is_order.hpp"
#	include <compare>
#	include <functional>
#	include <iterator>
#	include <ranges>

namespace xte {
	template<std::input_iterator Iter0, std::sentinel_for<Iter0> Sentinel0, std::input_iterator Iter1, std::sentinel_for<Iter1> Sentinel1, typename Cmp = decltype(xte::synth_three_way), typename Proj = decltype(xte::nop)>
	[[nodiscard]] constexpr auto range_cmp(Iter0 begin0, Sentinel0 end0, Iter1 begin1, Sentinel1 end1, Cmp&& cmp = {}, Proj&& proj = {})
	noexcept(xte::is_noex_iter<Iter0>
		&& xte::is_noex_sentinel<Sentinel0, Iter0>
		&& xte::is_noex_iter<Iter1>
		&& xte::is_noex_sentinel<Sentinel1, Iter1>
		&& noexcept(std::invoke(cmp, std::invoke(proj, *begin0), std::invoke(proj, *begin1))))
	requires(xte::is_order<decltype(std::invoke(cmp, std::invoke(proj, *begin0), std::invoke(proj, *begin1)))>) {
		bool exhaust0 = (begin0 == end0);
		bool exhaust1 = (begin1 == end1);
		for (; !exhaust0 && !exhaust1; void(exhaust0 = ++begin0 == end0), void(exhaust1 = ++begin1 == end1)) {
			if (auto result = std::invoke(cmp, std::invoke(proj, *begin0), std::invoke(proj, *begin1)); !std::is_eq(result)) {
				return result;
			}
		}
		return exhaust0 <=> exhaust1;
	}

	template<std::ranges::input_range Range, std::input_iterator Iter, std::sentinel_for<Iter> Sentinel, typename Cmp = decltype(xte::synth_three_way), typename Proj = decltype(xte::nop)>
	[[nodiscard]] constexpr auto range_cmp(Range&& lhs, Iter begin, Sentinel end, Cmp&& cmp = {}, Proj&& proj = {}) XTE_ARROW(
		xte::range_cmp(std::ranges::begin(lhs), std::ranges::end(lhs), begin, end, XTE_FWD(cmp), XTE_FWD(proj))
	)

	template<std::input_iterator Iter, std::sentinel_for<Iter> Sentinel, typename Cmp = decltype(xte::synth_three_way), typename Proj = decltype(xte::nop)>
	[[nodiscard]] constexpr auto range_cmp(Iter begin, Sentinel end, std::ranges::input_range auto&& rhs, Cmp&& cmp = {}, Proj&& proj = {}) XTE_ARROW(
		xte::range_cmp(begin, end, std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(cmp), XTE_FWD(proj))
	)

	template<std::ranges::input_range Range0, std::ranges::input_range Range1, typename Cmp = decltype(xte::synth_three_way), typename Proj = decltype(xte::nop)>
	[[nodiscard]] constexpr auto range_cmp(Range0&& lhs, Range1&& rhs, Cmp&& cmp = {}, Proj&& proj = {}) XTE_ARROW(
		xte::range_cmp(std::ranges::begin(lhs), std::ranges::end(lhs), std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(cmp), XTE_FWD(proj))
	)
}

#endif

// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare_three_way.html#Possible_implementation
