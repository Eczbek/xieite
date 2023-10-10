#pragma once

#include <type_traits>
#include "../concepts/uniform_random_bit_generator.hpp"

namespace xieite::traits {
	template<typename Type>
	struct UniformRandomBitGenerator
	: std::bool_constant<xieite::concepts::UniformRandomBitGenerator<Type>> {};
}
