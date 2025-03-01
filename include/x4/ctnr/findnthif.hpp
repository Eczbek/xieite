#pragma once

#include <cstddef>
#include <functional>
#include <ranges>
#include "../ctnr/iters.hpp"
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"
#include "../trait/isnoexrange.hpp"

namespace x4 {
	template<std::ranges::forward_range R, x4::isinvoc<bool(std::ranges::range_common_reference_t<R>)> F>
	[[nodiscard]] constexpr std::ranges::iterator_t<R> findnthif(R& range, std::size_t n, F&& cond = {})
	noexcept(x4::isnoexinvoc<F, bool(std::ranges::range_common_reference_t<R>)> && x4::isnoexrange<R>) {
		for (auto iter : x4::iters(range)) {
			if (std::invoke_r<bool>(cond, *iter) && !n--) {
				return iter;
			}
		}
		return std::ranges::end(range);
	}
}
