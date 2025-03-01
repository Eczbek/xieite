#pragma once

#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<typename T>
	constexpr auto cast =
		[][[nodiscard]](auto&& x)
			X4AR(static_cast<T>(X4FWD(x)));
}
