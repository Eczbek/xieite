#pragma once

#include <type_traits>
#include "../meta/t.hpp"
#include "../trait/is_unsigned.hpp"

namespace xieite {
	template<typename T>
	using try_sign = std::conditional_t<xieite::is_unsigned<T>, std::make_signed<T>, xieite::t<T>>::type;
}
