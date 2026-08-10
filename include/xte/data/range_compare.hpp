#ifndef DETAIL_XTE_HEADER_DATA_RANGE_COMPARE
#	define DETAIL_XTE_HEADER_DATA_RANGE_COMPARE
#
#	include "../func/noop.hpp"
#	include "../func/visitor.hpp"
#	include "../math/compare.hpp"
#	include "../meta/end.hpp"
#	include "../meta/fake.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/lift.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/is_iter_noex.hpp"
#	include "../trait/is_order.hpp"
#	include "../trait/is_sentinel_noex.hpp"
#	include <compare>
#	include <functional>
#	include <iterator>
#	include <ranges>

namespace xte {
	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::noop), xte::end...,
		xte::is_order return_type = decltype(xte::fake<compare_type&>()(std::invoke(xte::fake<proj_type&>(), *xte::fake<lhs_iter_type&>()), std::invoke(xte::fake<proj_type&>(), *xte::fake<rhs_iter_type&>())))>
	[[nodiscard]] constexpr return_type range_compare(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {})
	noexcept(xte::is_iter_noex<lhs_iter_type>
		&& xte::is_sentinel_noex<lhs_sentinel_type, lhs_iter_type>
		&& xte::is_iter_noex<rhs_iter_type>
		&& xte::is_sentinel_noex<rhs_sentinel_type, rhs_iter_type>
		&& noexcept(compare(std::invoke(proj, *lhs_begin), std::invoke(proj, *rhs_begin))))
	{
		bool exhaust0 = (lhs_begin == lhs_end);
		bool exhaust1 = (rhs_begin == rhs_end);
		while (!exhaust0 && !exhaust1) {
			if (return_type result = compare(std::invoke(proj, *lhs_begin), std::invoke(proj, *rhs_begin)); !std::is_eq(result)) {
				return result;
			}
			exhaust0 = static_cast<bool>(++lhs_begin == lhs_end);
			exhaust1 = static_cast<bool>(++rhs_begin == rhs_end);
		}
		return exhaust1 <=> exhaust0;
	}

	template<std::ranges::input_range lhs_range_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_compare(lhs_range_type&& lhs, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_compare(std::ranges::begin(lhs), std::ranges::end(lhs), rhs_begin, rhs_end, XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_compare(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_compare(lhs_begin, lhs_end, std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::ranges::input_range lhs_range_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_compare(lhs_range_type&& lhs, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_compare(std::ranges::begin(lhs), std::ranges::end(lhs), std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(compare), XTE_FWD(proj))
	)
}

#endif

// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare_three_way.html#Possible_implementation
