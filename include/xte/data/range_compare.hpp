#ifndef DETAIL_XTE_HEADER_DATA_RANGE_COMPARE
#	define DETAIL_XTE_HEADER_DATA_RANGE_COMPARE
#
#	include "../func/noop.hpp"
#	include "../func/visitor.hpp"
#	include "../math/compare.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/is_noex_iter.hpp"
#	include "../trait/is_noex_sentinel.hpp"
#	include "../trait/is_order.hpp"
#	include <compare>
#	include <functional>
#	include <iterator>
#	include <ranges>

namespace xte {
	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_compare(lhs_iter_type begin0, lhs_sentinel_type end0, rhs_iter_type begin1, rhs_sentinel_type end1, compare_type&& compare = {}, proj_type&& proj = {})
	noexcept(xte::is_noex_iter<lhs_iter_type>
		&& xte::is_noex_sentinel<lhs_sentinel_type, lhs_iter_type>
		&& xte::is_noex_iter<rhs_iter_type>
		&& xte::is_noex_sentinel<rhs_sentinel_type, rhs_iter_type>
		&& noexcept(std::invoke(compare, std::invoke(proj, *begin0), std::invoke(proj, *begin1))))
	requires(xte::is_order<decltype(std::invoke(compare, std::invoke(proj, *begin0), std::invoke(proj, *begin1)))>) {
		bool exhaust0 = (begin0 == end0);
		bool exhaust1 = (begin1 == end1);
		for (; !exhaust0 && !exhaust1; exhaust0 = static_cast<bool>(++begin0 == end0), exhaust1 = static_cast<bool>(++begin1 == end1)) {
			if (auto result = std::invoke(compare, std::invoke(proj, *begin0), std::invoke(proj, *begin1)); !std::is_eq(result)) {
				return result;
			}
		}
		return exhaust0 <=> exhaust1;
	}

	template<std::ranges::input_range lhs_range_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_compare(lhs_range_type&& lhs, rhs_iter_type begin, rhs_sentinel_type end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_compare(std::ranges::begin(lhs), std::ranges::end(lhs), begin, end, XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_compare(lhs_iter_type begin, lhs_sentinel_type end, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_compare(begin, end, std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::ranges::input_range lhs_range_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_compare(lhs_range_type&& lhs, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_compare(std::ranges::begin(lhs), std::ranges::end(lhs), std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(compare), XTE_FWD(proj))
	)
}

#endif

// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare_three_way.html#Possible_implementation
