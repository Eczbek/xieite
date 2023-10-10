#pragma once

#include <type_traits>
#include "../concepts/linear_shape.hpp"

namespace xieite::traits {
	template<typename Type>
	struct LinearShape
	: std::bool_constant<xieite::concepts::LinearShape<Type>> {};
}
