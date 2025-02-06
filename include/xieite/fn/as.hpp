#pragma once

#include <type_traits>
#include "../pp/arrow.hpp"

namespace xieite {
	template<typename T>
	constexpr auto as =
		[][[nodiscard]](std::type_identity_t<T> x)
		XIEITE_ARROW(x);
}
