#pragma once

#include <compare>
#include <ranges>
#include "../ctnr/toupper.hpp"
#include "../trait/is_ch.hpp"
#include "../trait/is_fwd_input_range.hpp"

namespace xieite {
	template<typename R0, typename R1>
	requires(xieite::is_fwd_input_range<R0, []<xieite::is_ch> {}> && xieite::is_fwd_input_range<R1, []<xieite::is_ch> {}>)
	[[nodiscard]] constexpr std::strong_ordering cmp_ignore_case(R0&& l, R1&& r) noexcept {
		auto iter0 = std::ranges::begin(l);
		auto iter1 = std::ranges::begin(r);
		while (true) {
			if (iter0 == l.end()) {
				return std::strong_ordering::less;
			}
			if (iter1 == r.end()) {
				return std::strong_ordering::greater;
			}
			if (std::strong_ordering order = xieite::toupper(*iter0) <=> xieite::toupper(*iter1); !std::is_eq(order)) {
				return order;
			}
			++iter0;
			++iter1;
		}
		return std::strong_ordering::equal;
	}
}
