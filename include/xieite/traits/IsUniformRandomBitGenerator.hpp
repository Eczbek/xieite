#ifndef XIEITE_HEADER__TRAITS__IS_UNIFORM_RANDOM_BIT_GENERATOR
#	define XIEITE_HEADER__TRAITS__IS_UNIFORM_RANDOM_BIT_GENERATOR

#	include <random>
#	include <type_traits>

namespace xieite::traits {
	template<typename Type>
	struct IsUniformRandomBitGenerator
	: std::bool_constant<std::uniform_random_bit_generator<std::remove_reference_t<Type>>> {};
}

#endif
