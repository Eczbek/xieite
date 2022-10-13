#pragma once
#include <random>
#include <type_traits>

namespace gcufl::concepts {
	template<typename T>
	concept UniformRandomGenerator = std::uniform_random_bit_generator<std::remove_reference_t<T>>;
}
