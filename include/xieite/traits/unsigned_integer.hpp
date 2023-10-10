#pragma once

#include <type_traits>
#include "../concepts/unsigned_integer.hpp"

namespace xieite::traits {
	template<typename Type>
	struct UnsignedInteger
	: std::bool_constant<xieite::concepts::UnsignedInteger<Type>> {};
}
