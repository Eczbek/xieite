#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_SENTINEL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_SENTINEL
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
	template<typename T, typename Iter>
	concept is_noex_sentinel =
		std::sentinel_for<T, Iter>
		&& xte::is_noex_ctor<T>
		&& xte::is_noex_copy_ctor<T>
		&& xte::is_noex_move_ctor<T>
		&& xte::is_noex_dtor<T>
		&& xte::is_noex_copy_assignable<T>
		&& xte::is_noex_move_assignable<T>
		&& xte::is_noex_swappable<T>
		&& requires(T s0, const T s1, Iter i0, const Iter i1) {
			{ s0 == i0 } noexcept -> xte::is_noex_bool_testable;
			{ s0 == i1 } noexcept -> xte::is_noex_bool_testable;
			{ s1 == i0 } noexcept -> xte::is_noex_bool_testable;
			{ s1 == i1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s0) == i0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s0) == i1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s1) == i0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s1) == i1 } noexcept -> xte::is_noex_bool_testable;
			{ s0 == xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ s0 == xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ s1 == xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ s1 == xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s0) == xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s0) == xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s1) == xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s1) == xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ i0 == s0 } noexcept -> xte::is_noex_bool_testable;
			{ i0 == s1 } noexcept -> xte::is_noex_bool_testable;
			{ i1 == s0 } noexcept -> xte::is_noex_bool_testable;
			{ i1 == s1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i0) == s0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i0) == s1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i1) == s0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i1) == s1 } noexcept -> xte::is_noex_bool_testable;
			{ i0 == xte::xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ i0 == xte::xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ i1 == xte::xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ i1 == xte::xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i0) == xte::xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i0) == xte::xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i1) == xte::xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i1) == xte::xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ s0 != i0 } noexcept -> xte::is_noex_bool_testable;
			{ s0 != i1 } noexcept -> xte::is_noex_bool_testable;
			{ s1 != i0 } noexcept -> xte::is_noex_bool_testable;
			{ s1 != i1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s0) != i0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s0) != i1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s1) != i0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s1) != i1 } noexcept -> xte::is_noex_bool_testable;
			{ s0 != xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ s0 != xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ s1 != xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ s1 != xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s0) != xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s0) != xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s1) != xte::xvalue(i0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(s1) != xte::xvalue(i1) } noexcept -> xte::is_noex_bool_testable;
			{ i0 != s0 } noexcept -> xte::is_noex_bool_testable;
			{ i0 != s1 } noexcept -> xte::is_noex_bool_testable;
			{ i1 != s0 } noexcept -> xte::is_noex_bool_testable;
			{ i1 != s1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i0) != s0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i0) != s1 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i1) != s0 } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i1) != s1 } noexcept -> xte::is_noex_bool_testable;
			{ i0 != xte::xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ i0 != xte::xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ i1 != xte::xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ i1 != xte::xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i0) != xte::xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i0) != xte::xvalue(s1) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i1) != xte::xvalue(s0) } noexcept -> xte::is_noex_bool_testable;
			{ xte::xvalue(i1) != xte::xvalue(s1) } noexcept -> xte::is_noex_bool_testable; }
		&& (!std::sized_sentinel_for<T, Iter>
			|| requires(T s0, const T s1, Iter i0, const Iter i1) {
				{ s0 - i0 } noexcept;
				{ s0 - i1 } noexcept;
				{ s1 - i0 } noexcept;
				{ s1 - i1 } noexcept;
				{ xte::xvalue(s0) - i0 } noexcept;
				{ xte::xvalue(s0) - i1 } noexcept;
				{ xte::xvalue(s1) - i0 } noexcept;
				{ xte::xvalue(s1) - i1 } noexcept;
				{ s0 - xte::xvalue(i0) } noexcept;
				{ s0 - xte::xvalue(i1) } noexcept;
				{ s1 - xte::xvalue(i0) } noexcept;
				{ s1 - xte::xvalue(i1) } noexcept;
				{ xte::xvalue(s0) - xte::xvalue(i0) } noexcept;
				{ xte::xvalue(s0) - xte::xvalue(i1) } noexcept;
				{ xte::xvalue(s1) - xte::xvalue(i0) } noexcept;
				{ xte::xvalue(s1) - xte::xvalue(i1) } noexcept;
				{ i0 - s0 } noexcept;
				{ i0 - s1 } noexcept;
				{ i1 - s0 } noexcept;
				{ i1 - s1 } noexcept;
				{ xte::xvalue(i0) - s0 } noexcept;
				{ xte::xvalue(i0) - s1 } noexcept;
				{ xte::xvalue(i1) - s0 } noexcept;
				{ xte::xvalue(i1) - s1 } noexcept;
				{ i0 - xte::xvalue(s0) } noexcept;
				{ i0 - xte::xvalue(s1) } noexcept;
				{ i1 - xte::xvalue(s0) } noexcept;
				{ i1 - xte::xvalue(s1) } noexcept;
				{ xte::xvalue(i0) - xte::xvalue(s0) } noexcept;
				{ xte::xvalue(i0) - xte::xvalue(s1) } noexcept;
				{ xte::xvalue(i1) - xte::xvalue(s0) } noexcept;
				{ xte::xvalue(i1) - xte::xvalue(s1) } noexcept; });
}

#endif
