#pragma once

#include <compare>
#include <ranges>
#include "../ctnr/toupper.hpp"
#include "../trait/isch.hpp"
#include "../trait/isfwdirange.hpp"

namespace x4 {
	template<typename R0, typename R1>
	requires(x4::isfwdirange<R0, []<x4::isch> {}> && x4::isfwdirange<R1, []<x4::isch> {}>)
	[[nodiscard]] constexpr std::strong_ordering cmpigncase(R0&& l, R1&& r) noexcept {
		auto iter0 = std::ranges::begin(l);
		auto iter1 = std::ranges::begin(r);
		while (true) {
			if (iter0 == l.end()) {
				return std::strong_ordering::less;
			}
			if (iter1 == r.end()) {
				return std::strong_ordering::greater;
			}
			if (std::strong_ordering order = x4::toupper(*iter0) <=> x4::toupper(*iter1); !std::is_eq(order)) {
				return order;
			}
			++iter0;
			++iter1;
		}
		return std::strong_ordering::equal;
	}
}
