#pragma once

#include <functional>
#include <iterator>
#include <ranges>
#include "../ctnr/iters.hpp"
#include "../trait/is_invoc.hpp"
#include "../trait/is_noex_invoc.hpp"
#include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::forward_range R, xieite::is_invoc<bool(std::ranges::range_common_reference_t<R>)> F>
	requires(std::ranges::sized_range<R>)
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<R>> find_most_consec_if(R& range, F&& cond = {})
	noexcept(xieite::is_noex_invoc<F, bool(std::ranges::range_common_reference_t<R>)> && xieite::is_noex_range<R>) {
		auto curr_begin = std::ranges::begin(range);
		auto curr_end = curr_begin;
		auto result_begin = curr_begin;
		auto result_end = curr_end;
		bool prev = false;
		for (auto iter : xieite::iters(range)) {
			const bool curr = std::invoke_r<bool>(cond, *iter);
			if (curr) {
				if (!prev) {
					curr_begin = iter;
					curr_end = iter;
				}
				++curr_end;
			} else if (prev && (std::ranges::distance(curr_begin, curr_end) > std::ranges::distance(result_begin, result_end))) {
				result_begin = curr_begin;
				result_end = curr_end;
			}
			prev = curr;
		}
		if (prev && (std::ranges::distance(curr_begin, curr_end) > std::ranges::distance(result_begin, result_end))) {
			return std::ranges::subrange<std::ranges::iterator_t<R>>(curr_begin, curr_end);
		}
		return std::ranges::subrange<std::ranges::iterator_t<R>>(result_begin, result_end);
	}
}
