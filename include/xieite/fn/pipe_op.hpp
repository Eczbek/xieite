#pragma once

#include <concepts>
#include <functional>
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite::pipe_op {
	template<typename T, std::invocable<T> F>
	constexpr auto operator|(T&& arg, F&& fn)
		XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(arg)))
}
