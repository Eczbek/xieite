#ifndef XIEITE_HEADER_CONCEPTS_UNIFORM_RANDOM_BIT_GENERATOR
#	define XIEITE_HEADER_CONCEPTS_UNIFORM_RANDOM_BIT_GENERATOR

#	include <random>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept UniformRandomBitGenerator = std::uniform_random_bit_generator<std::remove_reference_t<Type>>;
}

#endif
