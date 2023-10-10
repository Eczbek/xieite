#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Arithmetic = std::is_arithmetic_v<Type>;
}
