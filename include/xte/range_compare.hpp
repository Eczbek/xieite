#ifndef DETAIL_XTE_HEADER_RANGE_COMPARE
#	define DETAIL_XTE_HEADER_RANGE_COMPARE
#
#	include "./compare.hpp"
#	include "./identity.hpp"
#	include "./meta/end.hpp"
#	include "./meta/fake.hpp"
#	include "./preproc/fwd.hpp"
#	include "./preproc/lift.hpp"
#	include "./preproc/returns.hpp"
#	include "./qual_cast.hpp"
#	include "./trait/is_callable_lvalue.hpp"
#	include "./trait/is_iter_noex.hpp"
#	include "./trait/is_order.hpp"
#	include "./trait/is_sentinel_noex.hpp"
#	include <compare>
#	include <functional>
#	include <iterator>
#	include <ranges>

namespace xte {
	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity), xte::end...,
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

	template<std::ranges::input_range lhs_range_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_compare(lhs_range_type&& lhs, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_compare(std::ranges::begin(lhs), std::ranges::end(lhs), rhs_begin, rhs_end, XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_compare(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_compare(lhs_begin, lhs_end, std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::ranges::input_range lhs_range_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_compare(lhs_range_type&& lhs, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_compare(std::ranges::begin(lhs), std::ranges::end(lhs), std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, xte::is_callable_lvalue<bool(decltype(*xte::fake<lhs_iter_type&>()), decltype(*xte::fake<rhs_iter_type&>()))> compare_type = decltype(XTE_LIFT_INFIX(==)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr bool range_equal(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {})
	noexcept(xte::is_iter_noex<lhs_iter_type>
		&& xte::is_sentinel_noex<lhs_sentinel_type, lhs_iter_type>
		&& xte::is_iter_noex<rhs_iter_type>
		&& xte::is_sentinel_noex<rhs_sentinel_type, rhs_iter_type>
		&& noexcept(static_cast<bool>(compare(std::invoke(proj, *lhs_begin), std::invoke(proj, *rhs_begin)))))
	{
		bool exhaust0 = (lhs_begin == lhs_end);
		bool exhaust1 = (rhs_begin == rhs_end);
		while (!exhaust0 && !exhaust1) {
			if (!static_cast<bool>(compare(std::invoke(proj, *lhs_begin), std::invoke(proj, *rhs_begin)))) {
				return false;
			}
			exhaust0 = static_cast<bool>(++lhs_begin == lhs_end);
			exhaust1 = static_cast<bool>(++rhs_begin == rhs_end);
		}
		return exhaust1 == exhaust0;
	}

	template<std::ranges::input_range lhs_range_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT_INFIX(==)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_equal(lhs_range_type&& lhs, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_equal(std::ranges::begin(lhs), std::ranges::end(lhs), rhs_begin, rhs_end, XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT_INFIX(==)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_equal(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_equal(lhs_begin, lhs_end, std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::ranges::input_range lhs_range_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT_INFIX(==)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_equal(lhs_range_type&& lhs, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_equal(std::ranges::begin(lhs), std::ranges::end(lhs), std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(compare), XTE_FWD(proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_less(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_lt(xte::range_compare(xte::as_xvalue(lhs_begin), xte::as_xvalue(lhs_end), xte::as_xvalue(rhs_begin), xte::as_xvalue(lhs_end), compare, proj))
	)

	template<std::ranges::input_range lhs_range_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_less(lhs_range_type&& lhs, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_lt(xte::range_compare(lhs, xte::as_xvalue(rhs_begin), xte::as_xvalue(rhs_end), compare, proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_less(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_lt(xte::range_compare(xte::as_xvalue(lhs_begin), xte::as_xvalue(lhs_end), rhs, compare, proj))
	)

	template<std::ranges::input_range lhs_range_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_less(lhs_range_type&& lhs, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_lt(xte::range_compare(lhs, rhs, compare, proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_less_equal(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_lteq(xte::range_compare(xte::as_xvalue(lhs_begin), xte::as_xvalue(lhs_end), xte::as_xvalue(rhs_begin), xte::as_xvalue(lhs_end), compare, proj))
	)

	template<std::ranges::input_range lhs_range_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_less_equal(lhs_range_type&& lhs, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_lteq(xte::range_compare(lhs, xte::as_xvalue(rhs_begin), xte::as_xvalue(rhs_end), compare, proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_less_equal(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_lteq(xte::range_compare(xte::as_xvalue(lhs_begin), xte::as_xvalue(lhs_end), rhs, compare, proj))
	)

	template<std::ranges::input_range lhs_range_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_less_equal(lhs_range_type&& lhs, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_lteq(xte::range_compare(lhs, rhs, compare, proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_greater(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_gt(xte::range_compare(xte::as_xvalue(lhs_begin), xte::as_xvalue(lhs_end), xte::as_xvalue(rhs_begin), xte::as_xvalue(lhs_end), compare, proj))
	)

	template<std::ranges::input_range lhs_range_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_greater(lhs_range_type&& lhs, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_gt(xte::range_compare(lhs, xte::as_xvalue(rhs_begin), xte::as_xvalue(rhs_end), compare, proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_greater(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_gt(xte::range_compare(xte::as_xvalue(lhs_begin), xte::as_xvalue(lhs_end), rhs, compare, proj))
	)

	template<std::ranges::input_range lhs_range_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_greater(lhs_range_type&& lhs, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_gt(xte::range_compare(lhs, rhs, compare, proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_greater_equal(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_gteq(xte::range_compare(xte::as_xvalue(lhs_begin), xte::as_xvalue(lhs_end), xte::as_xvalue(rhs_begin), xte::as_xvalue(lhs_end), compare, proj))
	)

	template<std::ranges::input_range lhs_range_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_greater_equal(lhs_range_type&& lhs, rhs_iter_type rhs_begin, rhs_sentinel_type rhs_end, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_gteq(xte::range_compare(lhs, xte::as_xvalue(rhs_begin), xte::as_xvalue(rhs_end), compare, proj))
	)

	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_greater_equal(lhs_iter_type lhs_begin, lhs_sentinel_type lhs_end, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_gteq(xte::range_compare(xte::as_xvalue(lhs_begin), xte::as_xvalue(lhs_end), rhs, compare, proj))
	)

	template<std::ranges::input_range lhs_range_type, std::ranges::input_range rhs_range_type, typename compare_type = decltype(XTE_LIFT(xte::compare)), typename proj_type = decltype(xte::identity)>
	[[nodiscard]] constexpr auto range_greater_equal(lhs_range_type&& lhs, rhs_range_type&& rhs, compare_type&& compare = {}, proj_type&& proj = {}) XTE_RETURNS(
		std::is_gteq(xte::range_compare(lhs, rhs, compare, proj))
	)
}

#endif

// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare_three_way.html#Possible_implementation
