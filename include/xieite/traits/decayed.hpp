#pragma once

#include <type_traits>
#include "../concepts/decayed.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Decayed
	: std::bool_constant<xieite::concepts::Decayed<Type>> {};
}
