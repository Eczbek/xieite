#pragma once

#include <functional>
#include <ranges>
#include "../ctnr/iters.hpp"
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"
#include "../trait/isnoexrange.hpp"

namespace x4 {
	template<std::ranges::input_range R0, std::ranges::input_range R1, x4::isinvoc<bool(std::ranges::range_common_reference_t<R0>, std::ranges::range_common_reference_t<R1>)> F = std::ranges::equal_to>
	[[nodiscard]] constexpr bool rotd(R0&& range0, R1&& range1, F&& cmp = {})
	noexcept(x4::isnoexinvoc<F, bool(std::ranges::range_common_reference_t<R0>, std::ranges::range_common_reference_t<R1>)> && x4::isnoexrange<R0> && x4::isnoexrange<R1>) {
		if (std::ranges::size(range0) == std::ranges::size(range1)) {
			for (auto iter : x4::iters(range0)) {
				auto copy0 = iter;
				auto copy1 = std::ranges::begin(range1);
				while (copy1 != std::ranges::end(range1)) {
					if (copy0 == std::ranges::end(range0)) {
						copy0 = std::ranges::begin(range0);
					}
					if (!std::invoke_r<bool>(cmp, *copy0, *copy1)) {
						break;
					}
					++copy0;
					++copy1;
				}
				if (copy1 == std::ranges::end(range1)) {
					return true;
				}
			}
		}
		return false;
	}
}
