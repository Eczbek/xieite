#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_ITER_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_ITER_NOEX
#
#	include "../trait/is_constructible_noex.hpp"
#	include "../trait/is_copy_assignable_noex.hpp"
#	include "../trait/is_copy_constructible_noex.hpp"
#	include "../trait/is_destructible_noex.hpp"
#	include "../trait/is_move_assignable_noex.hpp"
#	include "../trait/is_move_constructible_noex.hpp"
#	include "../trait/is_bool_testable_noex.hpp"
#	include "../trait/is_swappable_noex.hpp"
#	include "../util/as_xvalue.hpp"
#	include <iterator>

namespace xte {
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
			|| requires(iter_type iter, const iter_type const_iter) {
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
				&& requires(iter_type iter, const iter_type const_iter) {
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
			|| requires(iter_type iter, const iter_type const_iter, std::iter_difference_t<iter_type> iter_diff, const std::iter_difference_t<iter_type> const_iter_diff) {
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
}

#endif
