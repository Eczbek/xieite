#pragma once

#include <type_traits>
#include "../concepts/unsigned_integer.hpp"

namespace xieite::math {
	template<typename Type>
	using AttemptSign = std::conditional_t<xieite::concepts::UnsignedInteger<Type>, std::make_signed<Type>, std::type_identity<Type>>::type;
}
