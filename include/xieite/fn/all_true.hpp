#pragma once

#include <functional>
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename F, typename... Args>
	[[nodiscard]] constexpr bool all_true(F&& fn, Args&&... args)
		XIEITE_ARROW_RET((... && std::invoke_r<bool>(fn, XIEITE_FWD(args))))
}
