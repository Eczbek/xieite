#pragma once
#include <type_traits> // std::is_arithmetic_v

namespace xieite::concepts {
	template<typename T>
	concept Arithmetic = std::is_arithmetic_v<T>;
}
