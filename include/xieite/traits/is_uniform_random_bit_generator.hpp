#ifndef XIEITE_HEADER__TRAITS__IS_UNIFORM_RANDOM_BIT_GENERATOR
#	define XIEITE_HEADER__TRAITS__IS_UNIFORM_RANDOM_BIT_GENERATOR

#	include <type_traits>
#	include "../concepts/uniform_random_bit_generator.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsUniformRandomBitGenerator
	: std::bool_constant<xieite::concepts::UniformRandomBitGenerator<Type>> {};
}

#endif
