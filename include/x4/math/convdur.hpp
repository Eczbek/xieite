#pragma once

#include <chrono>
#include <tuple>
#include "../trait/isdur.hpp"

namespace x4 {
	template<x4::isdur T, x4::isdur... Us>
	[[nodiscard]] constexpr std::tuple<Us...> convdur(T dur) noexcept {
		std::tuple<Us...> results;
		(..., (dur -= (std::get<Us>(results) = std::chrono::duration_cast<Us>(dur))));
		return results;
	}
}
