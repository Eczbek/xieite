#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename Type>
	concept UnsignedInteger = std::unsigned_integral<Type> && !std::same_as<Type, bool>;
}
