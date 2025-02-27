#pragma once

#include <functional>
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename F, typename... Args>
	[[nodiscard]] constexpr auto any_true(F&& fn, Args&&... args)
		XIEITE_ARROW((... || std::invoke_r<bool>(fn, XIEITE_FWD(args))))
}
