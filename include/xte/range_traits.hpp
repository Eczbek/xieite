#ifndef DETAIL_XTE_HEADER_RANGE_TRAITS
#	define DETAIL_XTE_HEADER_RANGE_TRAITS

#	include "./class_traits.hpp"
#	include "./meta/req.hpp"
#	include "./qual_traits.hpp"
#	include <iterator>
#	include <ranges>

namespace xte {
	template<typename range_type, decltype(auto)... predicates>
	concept is_range = std::ranges::range<range_type> && xte::req<std::ranges::range_value_t<range_type>, predicates...>;

	template<typename range_type, decltype(auto)... predicates>
	concept is_sized_range = std::ranges::sized_range<range_type> && xte::req<std::ranges::range_value_t<range_type>, predicates...>;

	template<typename range_type, decltype(auto)... predicates>
	concept is_contiguous_range = std::ranges::contiguous_range<range_type> && xte::req<std::ranges::range_value_t<range_type>, predicates...>;

	template<typename range_type, decltype(auto)... predicates>
	concept is_input_range = std::ranges::input_range<range_type> && xte::req<std::ranges::range_value_t<range_type>, predicates...>;

	template<typename range_type, decltype(auto)... predicates>
	concept is_input_sized_range = std::ranges::input_range<range_type> && std::ranges::sized_range<range_type> && xte::req<std::ranges::range_value_t<range_type>, predicates...>;

	template<typename iter_type>
	concept is_iter_noex =
		std::input_or_output_iterator<iter_type>
		&& xte::is_move_constructible_noex<iter_type>
		&& xte::is_destructible_noex<iter_type>
		&& xte::is_move_assignable_noex<iter_type>
		&& xte::is_swappable_noex<iter_type>
		&& requires(iter_type iter) {
			{ ++iter } noexcept;
			{ iter++ } noexcept;
			{ *iter } noexcept; }
		&& (!std::input_iterator<iter_type>
			|| requires(iter_type iter, iter_type const const_iter) {
				{ *const_iter } noexcept;
				{ *xte::as_xvalue(iter) } noexcept;
				{ *xte::as_xvalue(const_iter) } noexcept;
				{ std::ranges::iter_move(iter) } noexcept;
				{ std::ranges::iter_move(const_iter) } noexcept;
				{ std::ranges::iter_move(xte::as_xvalue(iter)) } noexcept;
				{ std::ranges::iter_move(xte::as_xvalue(const_iter)) } noexcept; })
		&& (!std::forward_iterator<iter_type>
			|| (xte::is_constructible_noex<iter_type>
				&& xte::is_copy_constructible_noex<iter_type>
				&& xte::is_copy_assignable_noex<iter_type>
				&& requires(iter_type iter, iter_type const const_iter) {
					{ iter == iter } noexcept -> xte::is_bool_testable_noex;
					{ iter == const_iter } noexcept -> xte::is_bool_testable_noex;
					{ const_iter == iter } noexcept -> xte::is_bool_testable_noex;
					{ const_iter == const_iter } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(iter) == iter } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(iter) == const_iter } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(const_iter) == iter } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(const_iter) == const_iter } noexcept -> xte::is_bool_testable_noex;
					{ iter == xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
					{ iter == xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
					{ const_iter == xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
					{ const_iter == xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(iter) == xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(iter) == xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(const_iter) == xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(const_iter) == xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
					{ iter != iter } noexcept -> xte::is_bool_testable_noex;
					{ iter != const_iter } noexcept -> xte::is_bool_testable_noex;
					{ const_iter != iter } noexcept -> xte::is_bool_testable_noex;
					{ const_iter != const_iter } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(iter) != iter } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(iter) != const_iter } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(const_iter) != iter } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(const_iter) != const_iter } noexcept -> xte::is_bool_testable_noex;
					{ iter != xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
					{ iter != xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
					{ const_iter != xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
					{ const_iter != xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(iter) != xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(iter) != xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(const_iter) != xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
					{ xte::as_xvalue(const_iter) != xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex; }))
		&& (!std::bidirectional_iterator<iter_type>
			|| requires(iter_type iter) {
				{ --iter } noexcept;
				{ iter-- } noexcept; })
		&& (!std::random_access_iterator<iter_type>
			|| requires(iter_type iter, iter_type const const_iter, std::iter_difference_t<iter_type> iter_diff, std::iter_difference_t<iter_type> const const_iter_diff) {
				{ iter += iter_diff } noexcept;
				{ iter += const_iter_diff } noexcept;
				{ iter += xte::as_xvalue(iter_diff) } noexcept;
				{ iter += xte::as_xvalue(const_iter_diff) } noexcept;
				{ iter -= iter_diff } noexcept;
				{ iter -= const_iter_diff } noexcept;
				{ iter -= xte::as_xvalue(iter_diff) } noexcept;
				{ iter -= xte::as_xvalue(const_iter_diff) } noexcept;
				{ iter + iter_diff } noexcept;
				{ iter + const_iter_diff } noexcept;
				{ const_iter + iter_diff } noexcept;
				{ const_iter + const_iter_diff } noexcept;
				{ xte::as_xvalue(iter) + iter_diff } noexcept;
				{ xte::as_xvalue(iter) + const_iter_diff } noexcept;
				{ xte::as_xvalue(const_iter) + iter_diff } noexcept;
				{ xte::as_xvalue(const_iter) + const_iter_diff } noexcept;
				{ iter + xte::as_xvalue(iter_diff) } noexcept;
				{ iter + xte::as_xvalue(const_iter_diff) } noexcept;
				{ const_iter + xte::as_xvalue(iter_diff) } noexcept;
				{ const_iter + xte::as_xvalue(const_iter_diff) } noexcept;
				{ xte::as_xvalue(iter) + xte::as_xvalue(iter_diff) } noexcept;
				{ xte::as_xvalue(iter) + xte::as_xvalue(const_iter_diff) } noexcept;
				{ xte::as_xvalue(const_iter) + xte::as_xvalue(iter_diff) } noexcept;
				{ xte::as_xvalue(const_iter) + xte::as_xvalue(const_iter_diff) } noexcept;
				{ iter_diff + iter } noexcept;
				{ iter_diff + const_iter } noexcept;
				{ const_iter_diff + iter } noexcept;
				{ const_iter_diff + const_iter } noexcept;
				{ xte::as_xvalue(iter_diff) + iter } noexcept;
				{ xte::as_xvalue(iter_diff) + const_iter } noexcept;
				{ xte::as_xvalue(const_iter_diff) + iter } noexcept;
				{ xte::as_xvalue(const_iter_diff) + const_iter } noexcept;
				{ iter_diff + xte::as_xvalue(iter) } noexcept;
				{ iter_diff + xte::as_xvalue(const_iter) } noexcept;
				{ const_iter_diff + xte::as_xvalue(iter) } noexcept;
				{ const_iter_diff + xte::as_xvalue(const_iter) } noexcept;
				{ xte::as_xvalue(iter_diff) + xte::as_xvalue(iter) } noexcept;
				{ xte::as_xvalue(iter_diff) + xte::as_xvalue(const_iter) } noexcept;
				{ xte::as_xvalue(const_iter_diff) + xte::as_xvalue(iter) } noexcept;
				{ xte::as_xvalue(const_iter_diff) + xte::as_xvalue(const_iter) } noexcept;
				{ iter - iter_diff } noexcept;
				{ iter - const_iter_diff } noexcept;
				{ const_iter - iter_diff } noexcept;
				{ const_iter - const_iter_diff } noexcept;
				{ xte::as_xvalue(iter) - iter_diff } noexcept;
				{ xte::as_xvalue(iter) - const_iter_diff } noexcept;
				{ xte::as_xvalue(const_iter) - iter_diff } noexcept;
				{ xte::as_xvalue(const_iter) - const_iter_diff } noexcept;
				{ iter - xte::as_xvalue(iter_diff) } noexcept;
				{ iter - xte::as_xvalue(const_iter_diff) } noexcept;
				{ const_iter - xte::as_xvalue(iter_diff) } noexcept;
				{ const_iter - xte::as_xvalue(const_iter_diff) } noexcept;
				{ xte::as_xvalue(iter) - xte::as_xvalue(iter_diff) } noexcept;
				{ xte::as_xvalue(iter) - xte::as_xvalue(const_iter_diff) } noexcept;
				{ xte::as_xvalue(const_iter) - xte::as_xvalue(iter_diff) } noexcept;
				{ xte::as_xvalue(const_iter) - xte::as_xvalue(const_iter_diff) } noexcept;
				{ iter - iter } noexcept;
				{ iter - const_iter } noexcept;
				{ const_iter - iter } noexcept;
				{ const_iter - const_iter } noexcept;
				{ xte::as_xvalue(iter) - iter } noexcept;
				{ xte::as_xvalue(iter) - const_iter } noexcept;
				{ xte::as_xvalue(const_iter) - iter } noexcept;
				{ xte::as_xvalue(const_iter) - const_iter } noexcept;
				{ iter - xte::as_xvalue(iter) } noexcept;
				{ iter - xte::as_xvalue(const_iter) } noexcept;
				{ const_iter - xte::as_xvalue(iter) } noexcept;
				{ const_iter - xte::as_xvalue(const_iter) } noexcept;
				{ xte::as_xvalue(iter) - xte::as_xvalue(iter) } noexcept;
				{ xte::as_xvalue(iter) - xte::as_xvalue(const_iter) } noexcept;
				{ xte::as_xvalue(const_iter) - xte::as_xvalue(iter) } noexcept;
				{ xte::as_xvalue(const_iter) - xte::as_xvalue(const_iter) } noexcept;
				{ iter[iter_diff] } noexcept;
				{ iter[const_iter_diff] } noexcept;
				{ const_iter[iter_diff] } noexcept;
				{ const_iter[const_iter_diff] } noexcept;
				{ xte::as_xvalue(iter)[iter_diff] } noexcept;
				{ xte::as_xvalue(iter)[const_iter_diff] } noexcept;
				{ xte::as_xvalue(const_iter)[iter_diff] } noexcept;
				{ xte::as_xvalue(const_iter)[const_iter_diff] } noexcept;
				{ iter[xte::as_xvalue(iter_diff)] } noexcept;
				{ iter[xte::as_xvalue(const_iter_diff)] } noexcept;
				{ const_iter[xte::as_xvalue(iter_diff)] } noexcept;
				{ const_iter[xte::as_xvalue(const_iter_diff)] } noexcept;
				{ xte::as_xvalue(iter)[xte::as_xvalue(iter_diff)] } noexcept;
				{ xte::as_xvalue(iter)[xte::as_xvalue(const_iter_diff)] } noexcept;
				{ xte::as_xvalue(const_iter)[xte::as_xvalue(iter_diff)] } noexcept;
				{ xte::as_xvalue(const_iter)[xte::as_xvalue(const_iter_diff)] } noexcept;
				{ iter < iter } noexcept -> xte::is_bool_testable_noex;
				{ iter < const_iter } noexcept -> xte::is_bool_testable_noex;
				{ const_iter < iter } noexcept -> xte::is_bool_testable_noex;
				{ const_iter < const_iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) < iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) < const_iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) < iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) < const_iter } noexcept -> xte::is_bool_testable_noex;
				{ iter < xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ iter < xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ const_iter < xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ const_iter < xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) < xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) < xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) < xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) < xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ iter > iter } noexcept -> xte::is_bool_testable_noex;
				{ iter > const_iter } noexcept -> xte::is_bool_testable_noex;
				{ const_iter > iter } noexcept -> xte::is_bool_testable_noex;
				{ const_iter > const_iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) > iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) > const_iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) > iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) > const_iter } noexcept -> xte::is_bool_testable_noex;
				{ iter > xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ iter > xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ const_iter > xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ const_iter > xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) > xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) > xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) > xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) > xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ iter <= iter } noexcept -> xte::is_bool_testable_noex;
				{ iter <= const_iter } noexcept -> xte::is_bool_testable_noex;
				{ const_iter <= iter } noexcept -> xte::is_bool_testable_noex;
				{ const_iter <= const_iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) <= iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) <= const_iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) <= iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) <= const_iter } noexcept -> xte::is_bool_testable_noex;
				{ iter <= xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ iter <= xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ const_iter <= xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ const_iter <= xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) <= xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) <= xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) <= xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) <= xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ iter >= iter } noexcept -> xte::is_bool_testable_noex;
				{ iter >= const_iter } noexcept -> xte::is_bool_testable_noex;
				{ const_iter >= iter } noexcept -> xte::is_bool_testable_noex;
				{ const_iter >= const_iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) >= iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) >= const_iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) >= iter } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) >= const_iter } noexcept -> xte::is_bool_testable_noex;
				{ iter >= xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ iter >= xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ const_iter >= xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ const_iter >= xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) >= xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(iter) >= xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) >= xte::as_xvalue(iter) } noexcept -> xte::is_bool_testable_noex;
				{ xte::as_xvalue(const_iter) >= xte::as_xvalue(const_iter) } noexcept -> xte::is_bool_testable_noex; });

	template<typename sentinel_type, typename iter_type>
	concept is_sentinel_noex =
		std::sentinel_for<sentinel_type, iter_type>
		&& xte::is_constructible_noex<sentinel_type>
		&& xte::is_copy_constructible_noex<sentinel_type>
		&& xte::is_move_constructible_noex<sentinel_type>
		&& xte::is_destructible_noex<sentinel_type>
		&& xte::is_copy_assignable_noex<sentinel_type>
		&& xte::is_move_assignable_noex<sentinel_type>
		&& xte::is_swappable_noex<sentinel_type>
		&& requires(sentinel_type s0, sentinel_type const s1, iter_type i0, iter_type const i1) {
			{ s0 == i0 } noexcept -> xte::is_bool_testable_noex;
			{ s0 == i1 } noexcept -> xte::is_bool_testable_noex;
			{ s1 == i0 } noexcept -> xte::is_bool_testable_noex;
			{ s1 == i1 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s0) == i0 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s0) == i1 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s1) == i0 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s1) == i1 } noexcept -> xte::is_bool_testable_noex;
			{ s0 == xte::as_xvalue(i0) } noexcept -> xte::is_bool_testable_noex;
			{ s0 == xte::as_xvalue(i1) } noexcept -> xte::is_bool_testable_noex;
			{ s1 == xte::as_xvalue(i0) } noexcept -> xte::is_bool_testable_noex;
			{ s1 == xte::as_xvalue(i1) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s0) == xte::as_xvalue(i0) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s0) == xte::as_xvalue(i1) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s1) == xte::as_xvalue(i0) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s1) == xte::as_xvalue(i1) } noexcept -> xte::is_bool_testable_noex;
			{ i0 == s0 } noexcept -> xte::is_bool_testable_noex;
			{ i0 == s1 } noexcept -> xte::is_bool_testable_noex;
			{ i1 == s0 } noexcept -> xte::is_bool_testable_noex;
			{ i1 == s1 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i0) == s0 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i0) == s1 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i1) == s0 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i1) == s1 } noexcept -> xte::is_bool_testable_noex;
			{ i0 == xte::as_xvalue(s0) } noexcept -> xte::is_bool_testable_noex;
			{ i0 == xte::as_xvalue(s1) } noexcept -> xte::is_bool_testable_noex;
			{ i1 == xte::as_xvalue(s0) } noexcept -> xte::is_bool_testable_noex;
			{ i1 == xte::as_xvalue(s1) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i0) == xte::as_xvalue(s0) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i0) == xte::as_xvalue(s1) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i1) == xte::as_xvalue(s0) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i1) == xte::as_xvalue(s1) } noexcept -> xte::is_bool_testable_noex;
			{ s0 != i0 } noexcept -> xte::is_bool_testable_noex;
			{ s0 != i1 } noexcept -> xte::is_bool_testable_noex;
			{ s1 != i0 } noexcept -> xte::is_bool_testable_noex;
			{ s1 != i1 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s0) != i0 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s0) != i1 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s1) != i0 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s1) != i1 } noexcept -> xte::is_bool_testable_noex;
			{ s0 != xte::as_xvalue(i0) } noexcept -> xte::is_bool_testable_noex;
			{ s0 != xte::as_xvalue(i1) } noexcept -> xte::is_bool_testable_noex;
			{ s1 != xte::as_xvalue(i0) } noexcept -> xte::is_bool_testable_noex;
			{ s1 != xte::as_xvalue(i1) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s0) != xte::as_xvalue(i0) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s0) != xte::as_xvalue(i1) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s1) != xte::as_xvalue(i0) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(s1) != xte::as_xvalue(i1) } noexcept -> xte::is_bool_testable_noex;
			{ i0 != s0 } noexcept -> xte::is_bool_testable_noex;
			{ i0 != s1 } noexcept -> xte::is_bool_testable_noex;
			{ i1 != s0 } noexcept -> xte::is_bool_testable_noex;
			{ i1 != s1 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i0) != s0 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i0) != s1 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i1) != s0 } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i1) != s1 } noexcept -> xte::is_bool_testable_noex;
			{ i0 != xte::as_xvalue(s0) } noexcept -> xte::is_bool_testable_noex;
			{ i0 != xte::as_xvalue(s1) } noexcept -> xte::is_bool_testable_noex;
			{ i1 != xte::as_xvalue(s0) } noexcept -> xte::is_bool_testable_noex;
			{ i1 != xte::as_xvalue(s1) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i0) != xte::as_xvalue(s0) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i0) != xte::as_xvalue(s1) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i1) != xte::as_xvalue(s0) } noexcept -> xte::is_bool_testable_noex;
			{ xte::as_xvalue(i1) != xte::as_xvalue(s1) } noexcept -> xte::is_bool_testable_noex; }
		&& (!std::sized_sentinel_for<sentinel_type, iter_type>
			|| requires(sentinel_type s0, sentinel_type const s1, iter_type i0, iter_type const i1) {
				{ s0 - i0 } noexcept;
				{ s0 - i1 } noexcept;
				{ s1 - i0 } noexcept;
				{ s1 - i1 } noexcept;
				{ xte::as_xvalue(s0) - i0 } noexcept;
				{ xte::as_xvalue(s0) - i1 } noexcept;
				{ xte::as_xvalue(s1) - i0 } noexcept;
				{ xte::as_xvalue(s1) - i1 } noexcept;
				{ s0 - xte::as_xvalue(i0) } noexcept;
				{ s0 - xte::as_xvalue(i1) } noexcept;
				{ s1 - xte::as_xvalue(i0) } noexcept;
				{ s1 - xte::as_xvalue(i1) } noexcept;
				{ xte::as_xvalue(s0) - xte::as_xvalue(i0) } noexcept;
				{ xte::as_xvalue(s0) - xte::as_xvalue(i1) } noexcept;
				{ xte::as_xvalue(s1) - xte::as_xvalue(i0) } noexcept;
				{ xte::as_xvalue(s1) - xte::as_xvalue(i1) } noexcept;
				{ i0 - s0 } noexcept;
				{ i0 - s1 } noexcept;
				{ i1 - s0 } noexcept;
				{ i1 - s1 } noexcept;
				{ xte::as_xvalue(i0) - s0 } noexcept;
				{ xte::as_xvalue(i0) - s1 } noexcept;
				{ xte::as_xvalue(i1) - s0 } noexcept;
				{ xte::as_xvalue(i1) - s1 } noexcept;
				{ i0 - xte::as_xvalue(s0) } noexcept;
				{ i0 - xte::as_xvalue(s1) } noexcept;
				{ i1 - xte::as_xvalue(s0) } noexcept;
				{ i1 - xte::as_xvalue(s1) } noexcept;
				{ xte::as_xvalue(i0) - xte::as_xvalue(s0) } noexcept;
				{ xte::as_xvalue(i0) - xte::as_xvalue(s1) } noexcept;
				{ xte::as_xvalue(i1) - xte::as_xvalue(s0) } noexcept;
				{ xte::as_xvalue(i1) - xte::as_xvalue(s1) } noexcept; });

	template<typename range_type>
	concept is_range_noex =
		std::ranges::range<range_type>
		&& xte::is_iter_noex<std::ranges::iterator_t<range_type>>
		&& xte::is_sentinel_noex<std::ranges::sentinel_t<range_type>, std::ranges::iterator_t<range_type>>
		&& requires(range_type range) {
			{ std::ranges::begin(range) } noexcept;
			{ std::ranges::end(range) } noexcept;
			{ std::ranges::cbegin(range) } noexcept;
			{ std::ranges::cend(range) } noexcept;
			{ std::ranges::rbegin(range) } noexcept;
			{ std::ranges::rend(range) } noexcept;
			{ std::ranges::crbegin(range) } noexcept;
			{ std::ranges::crend(range) } noexcept;
			{ std::ranges::size(range) } noexcept;
			{ std::ranges::ssize(range) } noexcept;
			{ std::ranges::empty(range) } noexcept;
			{ std::ranges::data(range) } noexcept;
			{ std::ranges::cdata(range) } noexcept; };
}

#endif
