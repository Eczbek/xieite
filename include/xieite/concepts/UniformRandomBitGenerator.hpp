#pragma once
#include <random> // std::uniform_random_bit_generator
#include <type_traits> // std::remove_reference_t

namespace xieite::concepts {
	template<typename T>
	concept UniformRandomBitGenerator = std::uniform_random_bit_generator<std::remove_reference_t<T>>;
}
