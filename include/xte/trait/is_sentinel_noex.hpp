#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SENTINEL_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SENTINEL_NOEX
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
		&& requires(sentinel_type s0, const sentinel_type s1, iter_type i0, const iter_type i1) {
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
