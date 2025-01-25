#pragma once

#include <tuple>
#include "../pp/fwd.hpp"
#include "../trait/collapse_fwd.hpp"

namespace xieite {
	template<typename T, typename... Args>
	[[nodiscard]] constexpr auto collapse_fwd_as_tuple(Args&&... args) noexcept {
		return std::forward_as_tuple(xieite::collapse_fwd<T>(XIEITE_FWD(args))...);
	}
}
