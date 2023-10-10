#pragma once

#include <type_traits>
#include "../concepts/integer.hpp"

namespace xieite::math {
	template<xieite::concepts::Integer Integer, bool sign>
	using ConditionalSign = std::conditional_t<sign, std::make_signed_t<Integer>, std::make_unsigned_t<Integer>>;
}
