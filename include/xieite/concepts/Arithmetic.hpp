#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Arithmetic = std::is_arithmetic_v<Any>;
}
