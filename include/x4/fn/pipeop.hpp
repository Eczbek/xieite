#pragma once

#include <concepts>
#include <functional>
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4::pipeop {
	template<typename T, std::invocable<T> F>
	[[nodiscard]] constexpr auto operator|(T&& arg, F&& fn)
		X4AR(std::invoke(X4FWD(fn), X4FWD(arg)))
}
