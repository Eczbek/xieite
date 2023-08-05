#ifndef XIEITE_HEADER__CONCEPTS__UNIFORM_RANDOM_BIT_GENERATOR
#	define XIEITE_HEADER__CONCEPTS__UNIFORM_RANDOM_BIT_GENERATOR

#	include "../traits/IsUniformRandomBitGenerator.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept UniformRandomBitGenerator = xieite::traits::IsUniformRandomBitGenerator<Type>::value;
}

#endif
