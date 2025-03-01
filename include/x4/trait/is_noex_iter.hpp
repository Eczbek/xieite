#pragma once

#include <iterator>
#include <utility>
#include "../trait/hasnoexcpass.hpp"
#include "../trait/hasnoexcpctor.hpp"
#include "../trait/hasnoedfltctor.hpp"
#include "../trait/hasnoexdtor.hpp"
#include "../trait/hasnoexmvass.hpp"
#include "../trait/hasnoexmvctor.hpp"
#include "../trait/isnoexbool_testable.hpp"
#include "../trait/isnoexswap.hpp"

namespace x4 {
	template<typename T>
	concept isnoexiter =
		std::input_or_output_iterator<T>
		&& x4::hasnoexmvctor<T>
		&& x4::hasnoexdtor<T>
		&& x4::hasnoexmvass<T>
		&& x4::isnoexswap<T>
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
			x4::hasnoedfltctor<T>
			&& x4::hasnoexcpctor<T>
			&& x4::hasnoexcpass<T>
			&& requires(T i0, const T i1) {
				{ i0 == i0 } noexcept -> x4::isnoexbool_testable;
				{ i0 == i1 } noexcept -> x4::isnoexbool_testable;
				{ i1 == i0 } noexcept -> x4::isnoexbool_testable;
				{ i1 == i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) == i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) == i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) == i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) == i1 } noexcept -> x4::isnoexbool_testable;
				{ i0 == std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i0 == std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i1 == std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i1 == std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) == std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) == std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) == std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) == std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i0 != i0 } noexcept -> x4::isnoexbool_testable;
				{ i0 != i1 } noexcept -> x4::isnoexbool_testable;
				{ i1 != i0 } noexcept -> x4::isnoexbool_testable;
				{ i1 != i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) != i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) != i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) != i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) != i1 } noexcept -> x4::isnoexbool_testable;
				{ i0 != std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i0 != std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i1 != std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i1 != std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) != std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) != std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) != std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) != std::move(i1) } noexcept -> x4::isnoexbool_testable;
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
				{ i0 < i0 } noexcept -> x4::isnoexbool_testable;
				{ i0 < i1 } noexcept -> x4::isnoexbool_testable;
				{ i1 < i0 } noexcept -> x4::isnoexbool_testable;
				{ i1 < i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) < i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) < i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) < i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) < i1 } noexcept -> x4::isnoexbool_testable;
				{ i0 < std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i0 < std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i1 < std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i1 < std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) < std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) < std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) < std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) < std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i0 > i0 } noexcept -> x4::isnoexbool_testable;
				{ i0 > i1 } noexcept -> x4::isnoexbool_testable;
				{ i1 > i0 } noexcept -> x4::isnoexbool_testable;
				{ i1 > i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) > i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) > i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) > i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) > i1 } noexcept -> x4::isnoexbool_testable;
				{ i0 > std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i0 > std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i1 > std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i1 > std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) > std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) > std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) > std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) > std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i0 <= i0 } noexcept -> x4::isnoexbool_testable;
				{ i0 <= i1 } noexcept -> x4::isnoexbool_testable;
				{ i1 <= i0 } noexcept -> x4::isnoexbool_testable;
				{ i1 <= i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) <= i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) <= i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) <= i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) <= i1 } noexcept -> x4::isnoexbool_testable;
				{ i0 <= std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i0 <= std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i1 <= std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i1 <= std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) <= std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) <= std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) <= std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) <= std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i0 >= i0 } noexcept -> x4::isnoexbool_testable;
				{ i0 >= i1 } noexcept -> x4::isnoexbool_testable;
				{ i1 >= i0 } noexcept -> x4::isnoexbool_testable;
				{ i1 >= i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) >= i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) >= i1 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) >= i0 } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) >= i1 } noexcept -> x4::isnoexbool_testable;
				{ i0 >= std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i0 >= std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ i1 >= std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ i1 >= std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) >= std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i0) >= std::move(i1) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) >= std::move(i0) } noexcept -> x4::isnoexbool_testable;
				{ std::move(i1) >= std::move(i1) } noexcept -> x4::isnoexbool_testable;
			}
		);
}
