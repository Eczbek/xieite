#pragma once

#include <iterator>
#include <utility>
#include "../trait/has_noex_cp_assign.hpp"
#include "../trait/has_noex_cp_ctor.hpp"
#include "../trait/has_noex_default_ctor.hpp"
#include "../trait/has_noex_dtor.hpp"
#include "../trait/has_noex_mv_assign.hpp"
#include "../trait/has_noex_mv_ctor.hpp"
#include "../trait/is_noex_bool_testable.hpp"
#include "../trait/is_noex_swap.hpp"

namespace xieite {
	template<typename T>
	concept is_noex_iter =
		std::input_or_output_iterator<T>
		&& xieite::has_noex_mv_ctor<T>
		&& xieite::has_noex_dtor<T>
		&& xieite::has_noex_mv_assign<T>
		&& xieite::is_noex_swap<T>
		&& requires(T i0) {
			{ ++i0 } noexcept;
			{ i0++ } noexcept;
			{ *i0 } noexcept;
		} && (!std::input_iterator<T>
			|| requires(T i0, const T i1) {
				{ *i1 } noexcept;
				{ *std::move(i0) } noexcept;
				{ *std::move(i1) } noexcept;
				{ std::ranges::iter_move(i0) } noexcept;
				{ std::ranges::iter_move(i1) } noexcept;
				{ std::ranges::iter_move(std::move(i0)) } noexcept;
				{ std::ranges::iter_move(std::move(i1)) } noexcept;
			}
		) && (!std::forward_iterator<T> || (
			xieite::has_noex_default_ctor<T>
			&& xieite::has_noex_cp_ctor<T>
			&& xieite::has_noex_cp_assign<T>
			&& requires(T i0, const T i1) {
				{ i0 == i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 == i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 == i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 == i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) == i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) == i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) == i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) == i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 == std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 == std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 == std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 == std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) == std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) == std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) == std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) == std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 != i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 != i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 != i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 != i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) != i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) != i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) != i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) != i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 != std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 != std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 != std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 != std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) != std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) != std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) != std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) != std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
			}
		)) && (!std::bidirectional_iterator<T>
			|| requires(T i0) {
				{ --i0 } noexcept;
				{ i0-- } noexcept;
			}
		) && (!std::random_access_iterator<T>
			|| requires(T i0, const T i1, std::iter_difference_t<T> d0, const std::iter_difference_t<T> d1) {
				{ i0 += d0 } noexcept;
				{ i0 += d1 } noexcept;
				{ i0 += std::move(d0) } noexcept;
				{ i0 += std::move(d1) } noexcept;
				{ i0 -= d0 } noexcept;
				{ i0 -= d1 } noexcept;
				{ i0 -= std::move(d0) } noexcept;
				{ i0 -= std::move(d1) } noexcept;
				{ i0 + d0 } noexcept;
				{ i0 + d1 } noexcept;
				{ i1 + d0 } noexcept;
				{ i1 + d1 } noexcept;
				{ std::move(i0) + d0 } noexcept;
				{ std::move(i0) + d1 } noexcept;
				{ std::move(i1) + d0 } noexcept;
				{ std::move(i1) + d1 } noexcept;
				{ i0 + std::move(d0) } noexcept;
				{ i0 + std::move(d1) } noexcept;
				{ i1 + std::move(d0) } noexcept;
				{ i1 + std::move(d1) } noexcept;
				{ std::move(i0) + std::move(d0) } noexcept;
				{ std::move(i0) + std::move(d1) } noexcept;
				{ std::move(i1) + std::move(d0) } noexcept;
				{ std::move(i1) + std::move(d1) } noexcept;
				{ d0 + i0 } noexcept;
				{ d0 + i1 } noexcept;
				{ d1 + i0 } noexcept;
				{ d1 + i1 } noexcept;
				{ std::move(d0) + i0 } noexcept;
				{ std::move(d0) + i1 } noexcept;
				{ std::move(d1) + i0 } noexcept;
				{ std::move(d1) + i1 } noexcept;
				{ d0 + std::move(i0) } noexcept;
				{ d0 + std::move(i1) } noexcept;
				{ d1 + std::move(i0) } noexcept;
				{ d1 + std::move(i1) } noexcept;
				{ std::move(d0) + std::move(i0) } noexcept;
				{ std::move(d0) + std::move(i1) } noexcept;
				{ std::move(d1) + std::move(i0) } noexcept;
				{ std::move(d1) + std::move(i1) } noexcept;
				{ i0 - d0 } noexcept;
				{ i0 - d1 } noexcept;
				{ i1 - d0 } noexcept;
				{ i1 - d1 } noexcept;
				{ std::move(i0) - d0 } noexcept;
				{ std::move(i0) - d1 } noexcept;
				{ std::move(i1) - d0 } noexcept;
				{ std::move(i1) - d1 } noexcept;
				{ i0 - std::move(d0) } noexcept;
				{ i0 - std::move(d1) } noexcept;
				{ i1 - std::move(d0) } noexcept;
				{ i1 - std::move(d1) } noexcept;
				{ std::move(i0) - std::move(d0) } noexcept;
				{ std::move(i0) - std::move(d1) } noexcept;
				{ std::move(i1) - std::move(d0) } noexcept;
				{ std::move(i1) - std::move(d1) } noexcept;
				{ i0 - i0 } noexcept;
				{ i0 - i1 } noexcept;
				{ i1 - i0 } noexcept;
				{ i1 - i1 } noexcept;
				{ std::move(i0) - i0 } noexcept;
				{ std::move(i0) - i1 } noexcept;
				{ std::move(i1) - i0 } noexcept;
				{ std::move(i1) - i1 } noexcept;
				{ i0 - std::move(i0) } noexcept;
				{ i0 - std::move(i1) } noexcept;
				{ i1 - std::move(i0) } noexcept;
				{ i1 - std::move(i1) } noexcept;
				{ std::move(i0) - std::move(i0) } noexcept;
				{ std::move(i0) - std::move(i1) } noexcept;
				{ std::move(i1) - std::move(i0) } noexcept;
				{ std::move(i1) - std::move(i1) } noexcept;
				{ i0[d0] } noexcept;
				{ i0[d1] } noexcept;
				{ i1[d0] } noexcept;
				{ i1[d1] } noexcept;
				{ std::move(i0)[d0] } noexcept;
				{ std::move(i0)[d1] } noexcept;
				{ std::move(i1)[d0] } noexcept;
				{ std::move(i1)[d1] } noexcept;
				{ i0[std::move(d0)] } noexcept;
				{ i0[std::move(d1)] } noexcept;
				{ i1[std::move(d0)] } noexcept;
				{ i1[std::move(d1)] } noexcept;
				{ std::move(i0)[std::move(d0)] } noexcept;
				{ std::move(i0)[std::move(d1)] } noexcept;
				{ std::move(i1)[std::move(d0)] } noexcept;
				{ std::move(i1)[std::move(d1)] } noexcept;
				{ i0 < i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 < i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 < i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 < i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) < i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) < i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) < i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) < i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 < std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 < std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 < std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 < std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) < std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) < std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) < std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) < std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 > i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 > i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 > i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 > i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) > i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) > i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) > i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) > i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 > std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 > std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 > std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 > std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) > std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) > std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) > std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) > std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 <= i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 <= i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 <= i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 <= i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) <= i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) <= i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) <= i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) <= i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 <= std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 <= std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 <= std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 <= std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) <= std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) <= std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) <= std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) <= std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 >= i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 >= i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 >= i0 } noexcept -> xieite::is_noex_bool_testable;
				{ i1 >= i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) >= i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) >= i1 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) >= i0 } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) >= i1 } noexcept -> xieite::is_noex_bool_testable;
				{ i0 >= std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i0 >= std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 >= std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ i1 >= std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) >= std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i0) >= std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) >= std::move(i0) } noexcept -> xieite::is_noex_bool_testable;
				{ std::move(i1) >= std::move(i1) } noexcept -> xieite::is_noex_bool_testable;
			}
		);
}

// Thanks to Halalaluyafail3 for original code
