#ifndef DETAIL_XTE_HEADER_DATA_RANGE_CMP
#	define DETAIL_XTE_HEADER_DATA_RANGE_CMP
#
#	include "../func/noop.hpp"
#	include "../func/visitor.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/is_noex_iter.hpp"
#	include "../trait/is_noex_sentinel.hpp"
#	include "../trait/is_order.hpp"
#	include "../util/synth_three_way.hpp"
#	include <compare>
#	include <functional>
#	include <iterator>
#	include <ranges>

namespace xte {
	template<std::input_iterator lhs_iter_type, std::sentinel_for<lhs_iter_type> lhs_sentinel_type, std::input_iterator rhs_iter_type, std::sentinel_for<rhs_iter_type> rhs_sentinel_type, typename cmp_type = decltype(xte::synth_three_way), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_cmp(lhs_iter_type begin0, lhs_sentinel_type end0, rhs_iter_type begin1, rhs_sentinel_type end1, cmp_type&& cmp = {}, proj_type&& proj = {})
	noexcept(xte::is_noex_iter<lhs_iter_type>
		&& xte::is_noex_sentinel<lhs_sentinel_type, lhs_iter_type>
		&& xte::is_noex_iter<rhs_iter_type>
		&& xte::is_noex_sentinel<rhs_sentinel_type, rhs_iter_type>
		&& noexcept(std::invoke(cmp, std::invoke(proj, *begin0), std::invoke(proj, *begin1))))
	requires(xte::is_order<decltype(std::invoke(cmp, std::invoke(proj, *begin0), std::invoke(proj, *begin1)))>) {
		bool exhaust0 = (begin0 == end0);
		bool exhaust1 = (begin1 == end1);
		for (; !exhaust0 && !exhaust1; exhaust0 = static_cast<bool>(++begin0 == end0), exhaust1 = static_cast<bool>(++begin1 == end1)) {
			if (auto result = std::invoke(cmp, std::invoke(proj, *begin0), std::invoke(proj, *begin1)); !std::is_eq(result)) {
				return result;
			}
		}
		return exhaust0 <=> exhaust1;
	}

	template<std::ranges::input_range range_type, std::input_iterator iter_type, std::sentinel_for<iter_type> sentinel_type, typename cmp_type = decltype(xte::synth_three_way), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_cmp(range_type&& lhs, iter_type begin, sentinel_type end, cmp_type&& cmp = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_cmp(std::ranges::begin(lhs), std::ranges::end(lhs), begin, end, XTE_FWD(cmp), XTE_FWD(proj))
	)

	template<std::input_iterator iter_type, std::sentinel_for<iter_type> sentinel_type, typename cmp_type = decltype(xte::synth_three_way), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_cmp(iter_type begin, sentinel_type end, std::ranges::input_range auto&& rhs, cmp_type&& cmp = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_cmp(begin, end, std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(cmp), XTE_FWD(proj))
	)

	template<std::ranges::input_range lhs_range_type, std::ranges::input_range rhs_range_type, typename cmp_type = decltype(xte::synth_three_way), typename proj_type = decltype(xte::noop)>
	[[nodiscard]] constexpr auto range_cmp(lhs_range_type&& lhs, rhs_range_type&& rhs, cmp_type&& cmp = {}, proj_type&& proj = {}) XTE_RETURNS(
		xte::range_cmp(std::ranges::begin(lhs), std::ranges::end(lhs), std::ranges::begin(rhs), std::ranges::end(rhs), XTE_FWD(cmp), XTE_FWD(proj))
	)
}

#endif

// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare_three_way.html#Possible_implementation
