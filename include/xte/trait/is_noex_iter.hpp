#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_ITER
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_ITER
#
#	include "../trait/is_noex_copy_assignable.hpp"
#	include "../trait/is_noex_copy_ctor.hpp"
#	include "../trait/is_noex_dtor.hpp"
#	include "../trait/is_noex_move_assignable.hpp"
#	include "../trait/is_noex_move_ctor.hpp"
#	include "../trait/is_noex_bool_testable.hpp"
#	include "../trait/is_noex_swappable.hpp"
#	include "../util/xvalue.hpp"
#	include <iterator>

namespace xte {
	template<typename T>
	concept is_noex_iter =
		std::input_or_output_iterator<T>
		&& xte::is_noex_move_ctor<T>
		&& xte::is_noex_dtor<T>
		&& xte::is_noex_move_assignable<T>
		&& xte::is_noex_swappable<T>
		&& requires(T i0) {
			{ ++i0 } noexcept;
			{ i0++ } noexcept;
			{ *i0 } noexcept; }
		&& (!std::input_iterator<T>
			|| requires(T i0, const T i1) {
				{ *i1 } noexcept;
				{ *xte::xvalue(i0) } noexcept;
				{ *xte::xvalue(i1) } noexcept;
				{ std::ranges::iter_move(i0) } noexcept;
				{ std::ranges::iter_move(i1) } noexcept;
				{ std::ranges::iter_move(xte::xvalue(i0)) } noexcept;
				{ std::ranges::iter_move(xte::xvalue(i1)) } noexcept; })
		&& (!std::forward_iterator<T>
			|| (xte::is_noex_ctor<T>
				&& xte::is_noex_copy_ctor<T>
				&& xte::is_noex_copy_assignable<T>
				&& requires(T i0, const T i1) {
					{ i0 == i0 } noexcept -> xte::is_noex_bool_testable;
					{ i0 == i1 } noexcept -> xte::is_noex_bool_testable;
					{ i1 == i0 } noexcept -> xte::is_noex_bool_testable;
					{ i1 == i1 } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i0) == i0 } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i0) == i1 } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i1) == i0 } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i1) == i1 } noexcept -> xte::is_noex_bool_testable;
					{ i0 == xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
					{ i0 == xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
					{ i1 == xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
					{ i1 == xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i0) == xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i0) == xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i1) == xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i1) == xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
					{ i0 != i0 } noexcept -> xte::is_noex_bool_testable;
					{ i0 != i1 } noexcept -> xte::is_noex_bool_testable;
					{ i1 != i0 } noexcept -> xte::is_noex_bool_testable;
					{ i1 != i1 } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i0) != i0 } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i0) != i1 } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i1) != i0 } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i1) != i1 } noexcept -> xte::is_noex_bool_testable;
					{ i0 != xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
					{ i0 != xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
					{ i1 != xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
					{ i1 != xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i0) != xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i0) != xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i1) != xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
					{ xte::xvalue(i1) != xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable; }))
		&& (!std::bidirectional_iterator<T>
			|| requires(T i0) {
				{ --i0 } noexcept;
				{ i0-- } noexcept; })
		&& (!std::random_access_iterator<T>
			|| requires(T i0, const T i1, std::iter_difference_t<T> d0, const std::iter_difference_t<T> d1) {
				{ i0 += d0 } noexcept;
				{ i0 += d1 } noexcept;
				{ i0 += xte::xvalue(d0) } noexcept;
				{ i0 += xte::xvalue(d1) } noexcept;
				{ i0 -= d0 } noexcept;
				{ i0 -= d1 } noexcept;
				{ i0 -= xte::xvalue(d0) } noexcept;
				{ i0 -= xte::xvalue(d1) } noexcept;
				{ i0 + d0 } noexcept;
				{ i0 + d1 } noexcept;
				{ i1 + d0 } noexcept;
				{ i1 + d1 } noexcept;
				{ xte::xvalue(i0) + d0 } noexcept;
				{ xte::xvalue(i0) + d1 } noexcept;
				{ xte::xvalue(i1) + d0 } noexcept;
				{ xte::xvalue(i1) + d1 } noexcept;
				{ i0 + xte::xvalue(d0) } noexcept;
				{ i0 + xte::xvalue(d1) } noexcept;
				{ i1 + xte::xvalue(d0) } noexcept;
				{ i1 + xte::xvalue(d1) } noexcept;
				{ xte::xvalue(i0) + xte::xvalue(d0) } noexcept;
				{ xte::xvalue(i0) + xte::xvalue(d1) } noexcept;
				{ xte::xvalue(i1) + xte::xvalue(d0) } noexcept;
				{ xte::xvalue(i1) + xte::xvalue(d1) } noexcept;
				{ d0 + i0 } noexcept;
				{ d0 + i1 } noexcept;
				{ d1 + i0 } noexcept;
				{ d1 + i1 } noexcept;
				{ xte::xvalue(d0) + i0 } noexcept;
				{ xte::xvalue(d0) + i1 } noexcept;
				{ xte::xvalue(d1) + i0 } noexcept;
				{ xte::xvalue(d1) + i1 } noexcept;
				{ d0 + xte::xvalue(i0) } noexcept;
				{ d0 + xte::xvalue(i1) } noexcept;
				{ d1 + xte::xvalue(i0) } noexcept;
				{ d1 + xte::xvalue(i1) } noexcept;
				{ xte::xvalue(d0) + xte::xvalue(i0) } noexcept;
				{ xte::xvalue(d0) + xte::xvalue(i1) } noexcept;
				{ xte::xvalue(d1) + xte::xvalue(i0) } noexcept;
				{ xte::xvalue(d1) + xte::xvalue(i1) } noexcept;
				{ i0 - d0 } noexcept;
				{ i0 - d1 } noexcept;
				{ i1 - d0 } noexcept;
				{ i1 - d1 } noexcept;
				{ xte::xvalue(i0) - d0 } noexcept;
				{ xte::xvalue(i0) - d1 } noexcept;
				{ xte::xvalue(i1) - d0 } noexcept;
				{ xte::xvalue(i1) - d1 } noexcept;
				{ i0 - xte::xvalue(d0) } noexcept;
				{ i0 - xte::xvalue(d1) } noexcept;
				{ i1 - xte::xvalue(d0) } noexcept;
				{ i1 - xte::xvalue(d1) } noexcept;
				{ xte::xvalue(i0) - xte::xvalue(d0) } noexcept;
				{ xte::xvalue(i0) - xte::xvalue(d1) } noexcept;
				{ xte::xvalue(i1) - xte::xvalue(d0) } noexcept;
				{ xte::xvalue(i1) - xte::xvalue(d1) } noexcept;
				{ i0 - i0 } noexcept;
				{ i0 - i1 } noexcept;
				{ i1 - i0 } noexcept;
				{ i1 - i1 } noexcept;
				{ xte::xvalue(i0) - i0 } noexcept;
				{ xte::xvalue(i0) - i1 } noexcept;
				{ xte::xvalue(i1) - i0 } noexcept;
				{ xte::xvalue(i1) - i1 } noexcept;
				{ i0 - xte::xvalue(i0) } noexcept;
				{ i0 - xte::xvalue(i1) } noexcept;
				{ i1 - xte::xvalue(i0) } noexcept;
				{ i1 - xte::xvalue(i1) } noexcept;
				{ xte::xvalue(i0) - xte::xvalue(i0) } noexcept;
				{ xte::xvalue(i0) - xte::xvalue(i1) } noexcept;
				{ xte::xvalue(i1) - xte::xvalue(i0) } noexcept;
				{ xte::xvalue(i1) - xte::xvalue(i1) } noexcept;
				{ i0[d0] } noexcept;
				{ i0[d1] } noexcept;
				{ i1[d0] } noexcept;
				{ i1[d1] } noexcept;
				{ xte::xvalue(i0)[d0] } noexcept;
				{ xte::xvalue(i0)[d1] } noexcept;
				{ xte::xvalue(i1)[d0] } noexcept;
				{ xte::xvalue(i1)[d1] } noexcept;
				{ i0[xte::xvalue(d0)] } noexcept;
				{ i0[xte::xvalue(d1)] } noexcept;
				{ i1[xte::xvalue(d0)] } noexcept;
				{ i1[xte::xvalue(d1)] } noexcept;
				{ xte::xvalue(i0)[xte::xvalue(d0)] } noexcept;
				{ xte::xvalue(i0)[xte::xvalue(d1)] } noexcept;
				{ xte::xvalue(i1)[xte::xvalue(d0)] } noexcept;
				{ xte::xvalue(i1)[xte::xvalue(d1)] } noexcept;
				{ i0 < i0 } noexcept -> xte::is_noex_bool_testable;
				{ i0 < i1 } noexcept -> xte::is_noex_bool_testable;
				{ i1 < i0 } noexcept -> xte::is_noex_bool_testable;
				{ i1 < i1 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) < i0 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) < i1 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) < i0 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) < i1 } noexcept -> xte::is_noex_bool_testable;
				{ i0 < xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ i0 < xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ i1 < xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ i1 < xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) < xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) < xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) < xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) < xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ i0 > i0 } noexcept -> xte::is_noex_bool_testable;
				{ i0 > i1 } noexcept -> xte::is_noex_bool_testable;
				{ i1 > i0 } noexcept -> xte::is_noex_bool_testable;
				{ i1 > i1 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) > i0 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) > i1 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) > i0 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) > i1 } noexcept -> xte::is_noex_bool_testable;
				{ i0 > xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ i0 > xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ i1 > xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ i1 > xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) > xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) > xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) > xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) > xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ i0 <= i0 } noexcept -> xte::is_noex_bool_testable;
				{ i0 <= i1 } noexcept -> xte::is_noex_bool_testable;
				{ i1 <= i0 } noexcept -> xte::is_noex_bool_testable;
				{ i1 <= i1 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) <= i0 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) <= i1 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) <= i0 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) <= i1 } noexcept -> xte::is_noex_bool_testable;
				{ i0 <= xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ i0 <= xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ i1 <= xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ i1 <= xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) <= xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) <= xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) <= xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) <= xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ i0 >= i0 } noexcept -> xte::is_noex_bool_testable;
				{ i0 >= i1 } noexcept -> xte::is_noex_bool_testable;
				{ i1 >= i0 } noexcept -> xte::is_noex_bool_testable;
				{ i1 >= i1 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) >= i0 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) >= i1 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) >= i0 } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) >= i1 } noexcept -> xte::is_noex_bool_testable;
				{ i0 >= xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ i0 >= xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ i1 >= xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ i1 >= xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) >= xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i0) >= xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) >= xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
				{ xte::xvalue(i1) >= xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable; });
}

#endif
