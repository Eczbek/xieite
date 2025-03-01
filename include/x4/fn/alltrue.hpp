#pragma once

#include <functional>
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<typename F, typename... Args>
	[[nodiscard]] constexpr bool alltrue(F&& fn, Args&&... args)
		X4ARRET((... && std::invoke_r<bool>(fn, X4FWD(args))))
}
