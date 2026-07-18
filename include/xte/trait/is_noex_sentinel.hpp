#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_SENTINEL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_SENTINEL
#
#	include "../trait/is_noex_copy_assignable.hpp"
#	include "../trait/is_noex_copy_constructible.hpp"
#	include "../trait/is_noex_dtor.hpp"
#	include "../trait/is_noex_move_assignable.hpp"
#	include "../trait/is_noex_move_constructible.hpp"
#	include "../trait/is_noex_bool_testable.hpp"
#	include "../trait/is_noex_swappable.hpp"
#	include "../util/as_xvalue.hpp"
#	include <iterator>

namespace xte {
	template<typename sentinel_type, typename iter_type>
	concept is_noex_sentinel =
		std::sentinel_for<sentinel_type, iter_type>
		&& xte::is_noex_constructible<sentinel_type>
		&& xte::is_noex_copy_constructible<sentinel_type>
		&& xte::is_noex_move_constructible<sentinel_type>
		&& xte::is_noex_dtor<sentinel_type>
		&& xte::is_noex_copy_assignable<sentinel_type>
		&& xte::is_noex_move_assignable<sentinel_type>
		&& xte::is_noex_swappable<sentinel_type>
		&& requires(sentinel_type s0, const sentinel_type s1, iter_type i0, const iter_type i1) {
			{ s0 == i0 } noexcept -> xte::is_noex_bool_testable;
			{ s0 == i1 } noexcept -> xte::is_noex_bool_testable;
			{ s1 == i0 } noexcept -> xte::is_noex_bool_testable;
			{ s1 == i1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s0) == i0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s0) == i1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s1) == i0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s1) == i1 } noexcept -> xte::is_noex_bool_testable;
			{ s0 == xte::as_xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ s0 == xte::as_xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ s1 == xte::as_xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ s1 == xte::as_xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s0) == xte::as_xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s0) == xte::as_xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s1) == xte::as_xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s1) == xte::as_xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ i0 == s0 } noexcept -> xte::is_noex_bool_testable;
			{ i0 == s1 } noexcept -> xte::is_noex_bool_testable;
			{ i1 == s0 } noexcept -> xte::is_noex_bool_testable;
			{ i1 == s1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i0) == s0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i0) == s1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i1) == s0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i1) == s1 } noexcept -> xte::is_noex_bool_testable;
			{ i0 == xte::as_xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ i0 == xte::as_xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ i1 == xte::as_xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ i1 == xte::as_xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i0) == xte::as_xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i0) == xte::as_xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i1) == xte::as_xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i1) == xte::as_xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ s0 != i0 } noexcept -> xte::is_noex_bool_testable;
			{ s0 != i1 } noexcept -> xte::is_noex_bool_testable;
			{ s1 != i0 } noexcept -> xte::is_noex_bool_testable;
			{ s1 != i1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s0) != i0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s0) != i1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s1) != i0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s1) != i1 } noexcept -> xte::is_noex_bool_testable;
			{ s0 != xte::as_xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ s0 != xte::as_xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ s1 != xte::as_xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ s1 != xte::as_xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s0) != xte::as_xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s0) != xte::as_xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s1) != xte::as_xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(s1) != xte::as_xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ i0 != s0 } noexcept -> xte::is_noex_bool_testable;
			{ i0 != s1 } noexcept -> xte::is_noex_bool_testable;
			{ i1 != s0 } noexcept -> xte::is_noex_bool_testable;
			{ i1 != s1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i0) != s0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i0) != s1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i1) != s0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i1) != s1 } noexcept -> xte::is_noex_bool_testable;
			{ i0 != xte::as_xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ i0 != xte::as_xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ i1 != xte::as_xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ i1 != xte::as_xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i0) != xte::as_xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i0) != xte::as_xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i1) != xte::as_xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::as_xvalue(i1) != xte::as_xvalue(s1) } noexcept -> xte::is_noex_bool_testable; }
		&& (!std::sized_sentinel_for<sentinel_type, iter_type>
			|| requires(sentinel_type s0, const sentinel_type s1, iter_type i0, const iter_type i1) {
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
}

#endif
