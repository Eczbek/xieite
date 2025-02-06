#pragma once

#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	constexpr auto cast =
		[][[nodiscard]](auto&& x)
		XIEITE_ARROW(static_cast<T>(XIEITE_FWD(x)));
}
