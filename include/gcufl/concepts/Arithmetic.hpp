#pragma once

#include <type_traits>


namespace gcufl::concepts {
	template<typename T>
	concept Arithmetic = std::is_arithmetic_v<T>;
}
