#pragma once
#include <type_traits> // std::is_arithmetic_v

namespace xieite::concepts {
	template<typename Any>
	concept Arithmetic = std::is_arithmetic_v<Any>;
}
