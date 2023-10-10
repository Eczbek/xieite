#pragma once

#include <concepts>
#include "../concepts/arithmetic.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Numeric = xieite::concepts::Arithmetic<Type> && !std::same_as<Type, bool>;
}
