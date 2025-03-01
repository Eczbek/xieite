#pragma once

#include <type_traits>
#include "../pp/ar.hpp"

namespace x4 {
	template<typename T>
	constexpr auto as =
		[][[nodiscard]](std::type_identity_t<T> x)
			X4AR(x);
}
